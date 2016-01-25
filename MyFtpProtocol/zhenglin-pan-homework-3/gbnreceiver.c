#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <inttypes.h>
#include <sys/time.h>
#include <sys/ioctl.h>

#define MAXLINE 256
#define MAXSIZE 1023
#define HEADER 16
#define TIMEOUT1 3
#define TIMEOUT2 0

#define LSREMOTE	"ls-remote"
#define LSLOCAL		"ls-local"
#define GET			"get"
#define PUT			"put"
#define EXIT		"exit"

uint32_t total;

typedef struct {
	uint32_t seqno;
	uint32_t ackno;
	uint32_t ttlno;
	uint16_t checksum;
	uint16_t size;
	unsigned char* content;
}Packet;

void syserr(char *msg) {
	perror(msg);
	exit(-1);
}

uint16_t checksumCalc(Packet* pkt) {
	uint32_t sum = 0;
	uint32_t seqno = pkt->seqno;
	uint32_t ackno = pkt->ackno;
	uint32_t ttlno = pkt->ttlno;
	uint16_t checksum = pkt->checksum;
	uint16_t size = pkt->size;
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

void toPacket(Packet* pkt, unsigned char* str, Packet** ack) {
	pkt->seqno = (uint32_t)(((uint16_t)((uint8_t)str[0]<<8)+(uint8_t)str[1])<<16)+(uint16_t)((uint8_t)str[2]<<8)+(uint8_t)str[3];
	pkt->ackno = (uint32_t)(((uint16_t)((uint8_t)str[4]<<8)+(uint8_t)str[5])<<16)+(uint16_t)((uint8_t)str[6]<<8)+(uint8_t)str[7];
	pkt->ttlno = (uint32_t)(((uint16_t)((uint8_t)str[8]<<8)+(uint8_t)str[9])<<16)+(uint16_t)((uint8_t)str[10]<<8)+(uint8_t)str[11];
	total = ntohl(pkt->ttlno);
	pkt->checksum = (uint16_t)(str[12]<<8)+(uint8_t)str[13];
	pkt->size = (uint16_t)(str[14]<<8)+(uint8_t)str[15];
	memset(pkt->content, 0, MAXSIZE);
	memcpy(pkt->content, str+HEADER, ntohs(pkt->size));
	pkt->checksum = checksumCalc(pkt);
}

Packet* nextPacket(uint16_t size, uint32_t *seq, uint32_t *ack, uint32_t *ttl) {
	Packet* packet = (Packet*)malloc(sizeof(Packet));
	packet->content = (unsigned char*)malloc((size+1)*sizeof(unsigned char));
	packet->size = htons(size);
	printf("inside size: %d\n", packet->size);
	uint32_t seqno = htonl(*seq), ackno = htonl(*ack), ttlno = htonl(*ttl);
	packet->seqno = seqno;
	packet->ackno = ackno;
	packet->ttlno = ttlno;
	packet->checksum = htonl(0);

	packet->checksum = checksumCalc(packet);
	printf("checksum: %"PRIu16"\n", packet->checksum);
	(*seq)++;
	return packet;
}

unsigned char* toString(Packet* pkt) {
	unsigned char* str = (unsigned char*)malloc((HEADER+pkt->size+1)*sizeof(char));
	str[0] = pkt->seqno >> 24; str[1] = pkt->seqno >> 16; str[2] = pkt->seqno >> 8; str[3] = pkt->seqno;
	str[4] = pkt->ackno >> 24; str[5] = pkt->ackno >> 16; str[6] = pkt->ackno >> 8; str[7] = pkt->ackno;
	str[8] = pkt->ttlno >> 24; str[9] = pkt->ttlno >> 16; str[10] = pkt->ttlno >> 8; str[11] = pkt->ttlno;
	str[12] = pkt->checksum >> 8; str[13] = pkt->checksum; str[14] = pkt->size >> 8; str[15] = pkt->size;
	if (pkt->size > 0)
		memcpy(str+16, pkt->content, pkt->size);
	return str;
}

int main(int argc, char *argv[]) {
	int sockfd, newsockfd, portno, n, rem, expsqno, result;
	pid_t pid;
	struct sockaddr_in serv_addr, clt_addr;
	socklen_t addrlen = sizeof(clt_addr);
	unsigned char buffer[MAXSIZE];
	unsigned char *filename, *file;
	FILE *fp;
	struct timeval tv;
	fd_set readfds, tempfds;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <port> <filename>\n", argv[0]);
		return 1;
	}

	portno = atoi(argv[1]);
	filename = argv[2];

	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sockfd < 0)
		syserr("can't open socket");
	printf("create socket...\n");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
		syserr("can't bind");
	printf("bind socket to port %d...\n", portno);

	listen(sockfd, 5);

	fp = fopen(filename, "wb");
	expsqno = 0;
	total = 0;
	unsigned char* str = (unsigned char*)malloc((HEADER+MAXSIZE+1)*sizeof(char));
	Packet* packet = (Packet*)malloc(sizeof(Packet));
	packet->content = (unsigned char*)malloc(MAXSIZE*sizeof(char));
	uint32_t seq = 0, ack = 0, ttl = 0;
	Packet* ackmsg = (Packet*)malloc(sizeof(Packet));
	ackmsg->seqno = 0; ackmsg->ackno = 0; ackmsg->ttlno = 0;
	ackmsg->size = 0; ackmsg->checksum = checksumCalc(ackmsg);

	while (1) {
		FD_ZERO(&readfds);
		FD_SET(sockfd, &readfds);
		tv.tv_sec = TIMEOUT1;
		tv.tv_usec = TIMEOUT2;
		result = select(sockfd + 1, &readfds, NULL, NULL, &tv);
		if (result < 0)
			syserr("can't receive file size from sender");
		if (result == 0)
			break;
		if (FD_ISSET(sockfd, &readfds)) {
			if ((n = recvfrom(sockfd, str, HEADER+MAXSIZE+1, 0, (struct sockaddr*)&clt_addr, &addrlen)) < 0)
				syserr("can't receive file size from sender");
			toPacket(packet, str, &ackmsg);
			if (packet->checksum)
				continue;
			if (expsqno >= ntohl(packet->seqno)) {
				// send ack
				if (expsqno == ntohl(packet->seqno)) {
					fwrite(packet->content, 1, ntohs(packet->size), fp);
					printf("\r%.0lf%c", (double)(expsqno+1) / total * 100, '%');
				}
				ackmsg->ackno = packet->seqno;
				ackmsg->checksum = 0;
				ackmsg->checksum = checksumCalc(ackmsg);
				unsigned char* ackstr = toString(ackmsg);
				if ((n = sendto(sockfd, ackstr, HEADER, 0, (struct sockaddr *)&clt_addr, sizeof(clt_addr))) < 0) {
					perror("sendto failed");
					return 0;
				}
				if (expsqno == ntohl(packet->seqno))
					expsqno++;
				continue;
			}
		}
	}
	printf("\n");
	close(sockfd);
	fclose(fp);
	printf("File has been received successfully\n");
	return 0;
}

