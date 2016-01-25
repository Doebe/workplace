// gcc -std=gnu99 -pthread Peer.c -o peer
// filename 1
// remove file
// check existing file

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
#include <sys/ioctl.h>
#include <pthread.h>

#define MAXLINE 255
#define MAXSIZE 511

#define LIST		"list"
#define EXIT		"exit"
#define DOWNLOAD	"download"
#define UPDATE		"update"

int PID;

typedef struct {
	char* filename;
	char* ip;
	int port;
} Entry;

void syserr(char* msg) {
	perror(msg);
	exit(-1);
}

int sendall(int s, char *buf, int *len) {
	int total = 0, bytesleft = *len, n;
	while (total < *len) {
		n = send(s, buf + total, bytesleft, 0);
		if (n == -1)
			break;
		total += n;
		bytesleft -= n;
	}
	*len = total;
	return n == -1 ? -1 : 0; // return -1 on failure, 0 on success
}

int recvall(int s, char *buf, int *len) {
	int total = 0, bytesleft = *len, n;
	char* bf = malloc(256);
    struct winsize w;
	while (total < *len) {
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
		memset(bf, 0, 256);
		n = recv(s, buf + total, 1, 0);
		if (n == -1)
			break;
		total += n;
		bytesleft -= n;
		int i;
		for (i = 0; i <= w.ws_col-10; i++) {
			if (i < (int)((double)total / (total + bytesleft) * (w.ws_col-10)))
				bf[i] = '=';
			else if (i > (int)((double)total / (total + bytesleft) * (w.ws_col-10)))
				bf[i] = ' ';
			else bf[i] = '>';
		}
		printf("\r%s%.0lf%c", bf, (double)total / (total + bytesleft) * 100, '%');
		usleep(10);
	}
	printf("\n");
	free(bf);
	*len = total;
	return n == -1 ? -1 : 0; // return -1 on failure, 0 on success
}

void doftp(int newsd) {
	FILE *fp;
	uint32_t filelen;
	int n;
	char rq[MAXLINE], *buffer;

	// read command
	if ((recv(newsd, &rq, MAXLINE, 0)) < 0) {
		syserr("can't receive from client");
		exit(0);
	}
	if (!strcmp(rq, DOWNLOAD)) {
		// receive the file name
		if (recv(newsd, &rq, MAXLINE, 0) < 0)
			syserr("can't receive from client");
		char * filename = rq;
		filename[strlen(filename)] = '\0';
		// send the size of the file
		fp = fopen(filename, "rb");
		if (!fp) {
			filelen = 0;
			filelen = htonl(filelen);
			n = send(newsd, &filelen, sizeof(int), 0);
			return;
		}
		fseek(fp, 0, SEEK_END);
		filelen = ftell(fp);
		rewind(fp);
		filelen = htonl(filelen);
		if (send(newsd, &filelen, sizeof(int), 0) < 0)
			syserr("can't send to client");
		// send the file
		filelen = ntohl(filelen);
		filelen++;
		buffer = (char *) malloc((filelen) * sizeof(char));
		fread(buffer, filelen-1, 1, fp);
		buffer[filelen-1] = '\0';
		fclose(fp);
		if (sendall(newsd, buffer, &filelen) < 0)
			syserr("can't send to client");
	}
}

void *doserver(void* pn) {
	pid_t pid;
	socklen_t addrlen;
	int sockfd, newsockfd, n, portno = (int)(long)pn;
	char buffer[MAXLINE];
	struct sockaddr_in serv_addr, clt_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		syserr("can't open socket");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
		syserr("can't bind");
	listen(sockfd, 5);

	for (;;) {
		addrlen = sizeof(clt_addr);
		if ((newsockfd = accept(sockfd, (struct sockaddr*) &clt_addr, &addrlen))
				< 0)
			syserr("can't accept");

		if (!(pid = fork())) {
			close(sockfd);
			doftp(newsockfd);
			close(newsockfd);
			exit(0);
		}
	}
	close(sockfd);
	pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
	FILE * fp;
	pid_t pid;
	Entry** peerlist = 0;
	uint32_t filelen;
	int sockfd, portno1, portno2, n, size, cltsock;
	char buffer[MAXLINE], *f, *arg1, *filename, *peer_ip;
	struct hostent* server;
	struct sockaddr_in serv_addr;

	if (argc == 2) {
		portno1 = 5000;
		portno2 = 6000;
	} else if (argc == 3) {
		portno1 = atoi(argv[2]);
		portno2 = 6000;
	} else if (argc == 4) {
		portno1 = atoi(argv[2]);
		portno2 = atoi(argv[3]);
	} else {
		fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
		return 1;
	}
	server = gethostbyname(argv[1]);
	if (!server) {
		fprintf(stderr, "ERROR: no such host: %s\n", argv[1]);
		return 2;
	}
	// create socket
	if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		syserr("can't open socket");

	// initialize serv_addr
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr = *((struct in_addr*) server->h_addr);
	serv_addr.sin_port = htons(portno1);

	// connect to server
	if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
		syserr("can't connect to server");
	printf("Connection to %s:%d established. Now awaiting commands...\n",
			inet_ntoa(serv_addr.sin_addr), portno1);

	//	signal(SIGINT, intHandler);
	portno2 = htonl(portno2);
	if ((send(sockfd, &portno2, sizeof(int), 0)) < 0) {
		syserr("can't receive port number from client");
		exit(0);
	}

	// execute ls on command line and write outcome into a file
	system("ls -p | grep -v / >ls-remote.txt");
	fp = fopen("ls-remote.txt", "rb");
	fseek(fp, 0, SEEK_END);
	filelen = ftell(fp);
	rewind(fp);
	filelen = htonl(filelen);
	// notify client the size of the file
	if (send(sockfd, &filelen, sizeof(int), 0) < 0)
		syserr("can't send to client");
	// send file to the client
	f = (char *) malloc((filelen + 1) * sizeof(char));
	fread(f, filelen, 1, fp);
	f[filelen] = '\0';
	fclose(fp);
	filelen = ntohl(filelen);
	if (sendall(sockfd, f, &filelen) < 0)
		syserr("can't send to client");
	// create server
	pthread_t sid;
	pthread_create(&sid, NULL, doserver, (void *)(long)ntohl(portno2));
	pthread_detach(sid);

	arg1 = malloc(sizeof(char) * MAXLINE);
	int y = 0;
	while (1) {
		// get command
		memset(buffer,0, MAXLINE*sizeof(char));
		printf("PLEASE ENTER MESSAGE: ");
		fgets(buffer, MAXLINE, stdin);
		n = strlen(buffer);
		if (n > 0)
			buffer[n-1] = '\0';
		// arg1 contains first part of command
		memset(arg1,0, sizeof(arg1));
		strcpy(arg1, strtok(buffer, " "));
		// list
		if (!strcmp(arg1, LIST)) {
			// send the request to do ls-remote
			arg1[4] = '\0';
			if ((n = send(sockfd, arg1, 5, 0)) < 0)
				syserr("can't send to server");
			// receive the size of the file
			if ((n = recv(sockfd, &filelen, sizeof(int), 0)) < 0)
				syserr("can't receive from server");
			if (!n)
				break;
			filelen = ntohl(filelen);
			// receive the file
			f = malloc((filelen) * sizeof(char));
			if (recvall(sockfd, f, &filelen) < 0)
				syserr("can't receive from server");
			n = 1;
			int i;
			for (i = 0; i < filelen; i++)
				if (f[i] == '\n')
					n++;
			// Save into data structure
			if (peerlist)
				peerlist = (Entry**) realloc(peerlist, n * sizeof(Entry*));
			else
				peerlist = (Entry**) calloc(n, sizeof(Entry*));
			// Parsing variables
			int j, k = 0;
			printf("%s", f);
			for (i = 0; i < filelen; i++) {
				for (j = i; j < filelen; j++)
					if (f[j] == ' ')
						break;
				i = j + 1;
				peerlist[k] = (Entry*) malloc(sizeof(Entry));
				peerlist[k]->filename = (char*) malloc(MAXLINE * sizeof(char));
				peerlist[k]->ip = (char*) malloc(MAXLINE * sizeof(char));
				// Parse filename
				j = 0;
				for (; i < filelen; i++) {
					if (f[i] == ',')
						break;
					peerlist[k]->filename[j++] = f[i];
				}
				peerlist[k]->filename[j] = '\0';
				i+=2;
				// Parse ip
				j = 0;
				for (; i < filelen; i++) {
					if (f[i] == ':')
						break;
					peerlist[k]->ip[j++] = f[i];
				}
				peerlist[k]->ip[j] = '\0';
				i++;
				// Parse port
				peerlist[k]->port = 0;
				for (j = i; j < filelen; j++) {
					if (f[j] == '\n' || f[j] == '\0')
						break;
					peerlist[k]->port = peerlist[k]->port * 10 + f[j] - '0';
				}
				i = j + 1;
				k++;
			}
			free(f);
		}
		// download
		else if (!strcmp(arg1, DOWNLOAD)) {
			// get the second argument, which is the file name
			filename = strtok(NULL, " ");
			int k = 0;
			int i = 0;
			int valid = 1;
			while (filename[i]) {
				if (filename[i] >= '0' && filename[i] <= '9')
					k = k * 10 + filename[i++] - '0';
				else {
					printf("Input should be a number.\n");
					valid = 0;
					break;
				}
			}
			if (peerlist[k] == NULL)
				valid = 0;
			if (!valid)
				continue;
			// create another socket to connect with another peer
			serv_addr.sin_family = AF_INET;
			fp = fopen(peerlist[k]->filename, "rb");
			if (fp) {
				printf("File already exists locally.\n");
				fclose(fp);
				continue;
			}
			if (strcmp(peerlist[k]->ip, "127.0.0.1") == 0)
				peerlist[k]->ip = argv[1];
			inet_aton(peerlist[k]->ip, &serv_addr.sin_addr);
			serv_addr.sin_port = htons(peerlist[k]->port);
			if ((cltsock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
				syserr("can't open socket");
			if (connect(cltsock, (struct sockaddr*) &serv_addr,
					sizeof(serv_addr)) < 0) {
				printf("can't connect to server: Connection refused.\n");
				continue;
			}
			// send get file request to server
			if (send(cltsock, arg1, MAXLINE, 0) < 0)
				syserr("can't send to server");
			if (send(cltsock, peerlist[k]->filename, MAXLINE, 0) < 0)
				syserr("can't send to server");
			// receive the size of the file
			recv(cltsock, &filelen, sizeof(int), 0);
			filelen = ntohl(filelen);
			if (!filelen) {
				printf("No such file on the remote directory\n");
				continue;
			}
			// receive the file
			f = malloc(filelen * sizeof(char));
			n = recvall(cltsock, f, &filelen);
			fp = fopen(peerlist[k]->filename, "wb");
			fwrite(f, 1, filelen, fp);
			fclose(fp);
			printf("Retrieve '%s' from remote server: successful\n",
					peerlist[k]->filename);
			close(cltsock);
			if (send(sockfd, UPDATE, MAXLINE, 0) < 0)
				syserr("can't send to server");
			if (send(sockfd, peerlist[k]->filename, MAXLINE, 0) < 0)
				syserr("can't send to server");
			free(f);
		}
		// exit
		else if (!strcmp(arg1, EXIT)) {
			// send command to server
			break;
		} else {
			printf("unrecognized command, please try again.\n");
		}
	}
	if (send(sockfd, "exit", MAXLINE, 0) < 0)
		syserr("can't send to server");
	printf("Connection to server %s:%d terminated. Bye now!\n",
			inet_ntoa(serv_addr.sin_addr), ntohl(portno2));
	free(arg1);
	close(sockfd);
	return 0;
}
