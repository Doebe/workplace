#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>
#include <inttypes.h>
#include <sys/time.h>

#define MAXLINE 256
#define MAXSIZE 1023
#define HEADER 16
#define WINDOW 100
#define TIMEOUT1 0
#define TIMEOUT2 10000

#define LSREMOTE	"ls-remote"
#define LSLOCAL		"ls-local"
#define GET			"get"
#define PUT			"put"
#define EXIT		"exit"

#define min(a, b) a<b?a:b

sem_t windowsize;
pthread_mutex_t var_mtx;
uint32_t rem, window, expsqno, curackno, totalno;
uint32_t seqno, ackno, ttlno, leftseqno;
unsigned char *stt, *lst;

typedef struct {
	uint32_t seqno;
	uint32_t ackno;
	uint32_t ttlno;
	uint16_t checksum;
	uint16_t size;
	unsigned char* content;
}Packet;

void syserr(char* msg) {
	perror(msg);
	exit(-1);
}

void * receiveACK(void* s) {
	int fd, result;
	struct timeval tv;
	fd_set readfds, tempfds;

	fd = (int)(long)s;
	unsigned char* buf = (unsigned char*)malloc(HEADER*sizeof(char));
	tv.tv_sec = TIMEOUT1;
	tv.tv_usec = TIMEOUT2;
	curackno = 0;
	while (curackno < totalno) {
		FD_ZERO(&readfds);
		FD_SET(fd, &readfds);
		result = select(fd + 1, &readfds, NULL, NULL, &tv);
		if (result < 0)
			syserr("can't receive file size from sender");
		if (result == 0) {
			// retransmit
			pthread_mutex_lock(&var_mtx);
			rem = window;
			stt = lst;
			seqno = leftseqno;
			tv.tv_sec = TIMEOUT1;
			tv.tv_usec = TIMEOUT2;
			int sm;
			sem_getvalue(&windowsize, &sm);
			int dif1 = totalno-curackno;
			int dif2 = WINDOW-sm;
			int tmp = min(dif1, dif2);
			while (tmp-- > 0) {
				sem_post(&windowsize);
			}
			sem_getvalue(&windowsize, &sm);
			pthread_mutex_unlock(&var_mtx);
			continue;
		}
		if (FD_ISSET(fd, &readfds)) {
			// receive
			int n;
			if ((n = recvfrom(fd, buf, HEADER, 0, NULL, NULL)) < 0)
				syserr("can't receive file size from sender");
			// read packet;
			uint32_t thisackno = ntohl((uint32_t)(((uint16_t)((uint8_t)buf[4]<<8)+(uint8_t)buf[5])<<16)+(uint16_t)((uint8_t)buf[6]<<8)+(uint8_t)buf[7]);
			if (thisackno >= curackno) {
				pthread_mutex_lock(&var_mtx);
				int sm;
				sem_getvalue(&windowsize, &sm);
				int dif1 = totalno-thisackno;
				int dif2 = WINDOW-sm;
				int tmp = min(dif1, dif2);
				while (thisackno >= curackno) {
					curackno++;
					window -= MAXSIZE;
					lst += MAXSIZE;
					leftseqno++;
					if (tmp-->0) {
						sem_post(&windowsize);
					}
				}
				tv.tv_sec = TIMEOUT1;
				tv.tv_usec = TIMEOUT2;
				pthread_mutex_unlock(&var_mtx);
			}
		}
	}
	sem_post(&windowsize);
	pthread_exit(NULL);
}

uint16_t checksumCalc(Packet* pkt) {
	uint32_t sum = 0, seqno = pkt->seqno, ackno = pkt->ackno, ttlno = pkt->ttlno;
	uint16_t checksum = pkt->checksum, size = pkt->size;
	sum += seqno >> 16 & 0xFFFF;
	sum += seqno & 0xFFFF;
	sum += ackno >> 16 & 0xFFFF;
	sum += ackno & 0xFFFF;
	sum += ttlno >> 16 & 0xFFFF;
	sum += ttlno & 0xFFFF;
	sum += size;

	int flag = 0;
	int i = 0;
	size = ntohs(size);
	uint16_t cur = 0;
	while (i < size) {
		cur += *(pkt->content+i) & 0xFF;
		if (++i < size && !flag)
			cur <<= 8;
		if (i == size || flag) {
			sum += cur;
			cur = 0;
		}
		flag = 1-flag;
	}

	uint16_t bm = 0x00FF;
	uint16_t cksm = sum & bm;
	uint16_t carryover = (sum >> 16) & bm;
	cksm += carryover;
	cksm += checksum;
	return ~cksm;
}

Packet* nextPacket(uint16_t size) {
	Packet* packet = (Packet*)malloc(sizeof(Packet));
	packet->size = htons(size);
	packet->content = (unsigned char*)malloc((size+1)*sizeof(unsigned char));
	packet->seqno = htonl(seqno);
	packet->ackno = htonl(ackno);
	packet->ttlno = htonl(ttlno);
	packet->checksum = htonl(0);
	unsigned char* end = stt + ntohs(packet->size);
	memcpy(packet->content, stt, ntohs(packet->size));
	packet->checksum = checksumCalc(packet);
	stt = end;
	rem -= ntohs(packet->size);
	seqno++;
	return packet;
}

unsigned char* toString(Packet* pkt) {
	unsigned char* str = (unsigned char*)malloc((HEADER+pkt->size+1)*sizeof(char));
	str[0] = pkt->seqno >> 24; str[1] = pkt->seqno >> 16; str[2] = pkt->seqno >> 8; str[3] = pkt->seqno;
	str[4] = pkt->ackno >> 24; str[5] = pkt->ackno >> 16; str[6] = pkt->ackno >> 8; str[7] = pkt->ackno;
	str[8] = pkt->ttlno >> 24; str[9] = pkt->ttlno >> 16; str[10] = pkt->ttlno >> 8; str[11] = pkt->ttlno;
	str[12] = pkt->checksum >> 8; str[13] = pkt->checksum; str[14] = pkt->size >> 8; str[15] = pkt->size;
	memcpy(str+16, pkt->content, pkt->size);
	return str;
}

int main(int argc, char* argv[]) {
	int sockfd, portno, n, size;
	uint32_t filelen;
	struct hostent* server;
	struct sockaddr_in serv_addr;
	unsigned char *buffer, *filename;
	FILE* fp;
	if (argc != 4) {
		fprintf(stderr, "Usage: %s <hostname> <port> <filename>\n", argv[0]);
		return 1;
	}
	server = gethostbyname(argv[1]);
	if (!server) {
		fprintf(stderr, "ERROR: no such host: %s\n", argv[1]);
		return 2;
	}
	portno = atoi(argv[2]);
	filename = argv[3];

	// create socket
	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sockfd < 0)
		syserr("can't open socket");
	printf("create socket...\n");

	// initialize serv_addr
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr = *((struct in_addr*) server->h_addr);
	serv_addr.sin_port = htons(portno);

	fp = fopen(filename, "rb"); fseek(fp, 0, SEEK_END);
	filelen = ftell(fp); rewind(fp);
	buffer = (unsigned char*)malloc((filelen+1) * sizeof(char));
	memset(buffer, 0, filelen);
	fread(buffer, filelen, 1, fp);
	fclose(fp);
	buffer[filelen] = '\0';
	rem = filelen;
	window = filelen;

	seqno = 0, ackno = 0, ttlno = filelen%MAXSIZE?filelen/MAXSIZE+1:filelen/MAXSIZE;
	leftseqno = 0;
	totalno = ttlno;
	sem_init(&windowsize, 1, min(WINDOW, ttlno));
	pthread_t rcv;
	pthread_create(&rcv, NULL, receiveACK, (void*)(long)sockfd);
	stt = buffer;
	lst = buffer;

	struct timeval t1, t2;
	gettimeofday(&t1, NULL);

	while (curackno < totalno) {
		sem_wait(&windowsize);
		pthread_mutex_lock(&var_mtx);
		if (rem > 0) {
			uint16_t size = rem < MAXSIZE ? rem : MAXSIZE;

			Packet* packet = nextPacket(size);
			unsigned char* str = toString(packet);

			if ((n = sendto(sockfd, str, HEADER+size+1, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0) {
				perror("sendto failed");
				return 0;
			}
			free(packet);
			free(str);
		}
		pthread_mutex_unlock(&var_mtx);
	}
	gettimeofday(&t2, NULL);
	double diff = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec)/1000000.0;
	double throughput = filelen * 8 / diff;
	pthread_join(rcv, NULL);
	close(sockfd);
	printf("File has been sent successfully.\n");
	printf("The throughput is: %.2lf bits/sec\n", throughput);
	return 0;
}
