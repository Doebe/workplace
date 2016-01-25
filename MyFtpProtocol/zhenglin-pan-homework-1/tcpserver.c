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

#define MAXLINE 256
#define MAXSIZE 512

#define LSREMOTE	"ls-remote"
#define LSLOCAL		"ls-local"
#define GET			"get"
#define PUT			"put"
#define EXIT		"exit"

void syserr(char *msg) {
	perror(msg);
	exit(-1);
}

int sendall(int s, char *buf, int *len) {
	int total = 0;        // how many bytes we've sent
	int bytesleft = *len; // how many we have left to send
	int n;

	while (total < *len) {
		n = send(s, buf + total, bytesleft, 0);
		if (n == -1)
			break;
		total += n;
		bytesleft -= n;
	}
	*len = total; // return number actually sent here
	return n == -1 ? -1 : 0; // return -1 on failure, 0 on success
}

int recvall(int s, char *buf, int *len) {
	int total = 0;        // how many bytes we've read
	int bytesleft = *len; // how many we have left to read
	int n;

	while (total < *len) {
		n = recv(s, buf + total, bytesleft, 0);
		if (n == -1)
			break;
		total += n;
		bytesleft -= n;
	}
	*len = total; // return number actually sent here
	return n == -1 ? -1 : 0; // return -1 on failure, 0 on success
}

void doftp(int newsd) {
	int n;
	uint32_t filelen;
	char rq[MAXLINE], *buffer;
	FILE *fp;

	while(1) {
		// read command
		if ((recv(newsd, &rq, MAXLINE, 0)) < 0) {
			syserr("can't receive from client");
			exit(0);
		}

		// ls-remote
		if (!strcmp(rq, LSREMOTE)) {
			// execute ls on command line and write outcome into a file
			system("ls >ls-remote.txt");
			fp = fopen("ls-remote.txt", "rb");
			fseek(fp, 0, SEEK_END);
			filelen = ftell(fp);
			rewind(fp);
			filelen = htonl(filelen);

			// notify client the size of the file
			n = send(newsd, &filelen, sizeof(int), 0);
			if (n < 0)
				syserr("can't send to client");

			// send file to the client
			buffer = (char *) malloc((filelen + 1) * sizeof(char));
			fread(buffer, filelen, 1, fp);
			buffer[filelen + 1] = '\0';
			fclose(fp);
			filelen = ntohl(filelen);
			n = sendall(newsd, buffer, &filelen);
			if (n < 0)
				syserr("can't send to client");
			printf("mission completed\n");
		}
		// get filename
		else if (!strcmp(rq, GET)) {
			// receive the file name
			n = recv(newsd, &rq, MAXLINE, 0);
			if (n < 0)
				syserr("can't receive from client");
			char * filename = rq;

			// send the size of the file
			fp = fopen(filename, "rb");
			if (!fp) {
				filelen = 0;
				filelen = htonl(filelen);
				n = send(newsd, &filelen, sizeof(int), 0);
				continue;
			}
			fseek(fp, 0, SEEK_END);
			filelen = ftell(fp);
			rewind(fp);
			filelen = htonl(filelen);
			n = send(newsd, &filelen, sizeof(int), 0);
			if (n < 0)
				syserr("can't send to client");

			// send the file
			buffer = (char *) malloc((filelen + 1) * sizeof(char));
			fread(buffer, filelen, 1, fp);
			buffer[filelen + 1] = '\0';
			fclose(fp);
			filelen = ntohl(filelen);
			n = sendall(newsd, buffer, &filelen);
			if (n < 0)
				syserr("can't send to client");
			printf("mission completed\n");
		}
		// put filename
		else if (!strcmp(rq, PUT)) {
			// receive the file name
			n = recv(newsd, &rq, MAXLINE, 0);
			if (n < 0)
				syserr("can't receive from client");
			char * filename = rq;

			// receive the file size
			recv(newsd, &filelen, sizeof(int), 0);
			if (!filelen) {
				printf("yes\n");
				continue;
			}
			filelen = ntohl(filelen);

			// receive the file
			buffer = malloc(filelen);
			n = recvall(newsd, buffer, &filelen);
			if (n < 0)
				syserr("can't receive from client");
			fp = fopen(filename, "wb");
			fwrite(buffer, 1, filelen, fp);
			fclose(fp);
			buffer = "received";
			n = send(newsd, buffer, MAXSIZE, 0);
			if (n < 0)
				syserr("can't send to client");
			printf("mission completed\n");
		}
		// exit
		else if (!strcmp(rq, EXIT)) {
			printf("FILE TRANSFER COMPLETE ON SOCKET %d\n", newsd);
			break;
		}
	}
	printf("FILE TRANSFER HAS BEEN SUCCESSFULLY CLOSED\n");
}

int main(int argc, char *argv[]) {
	int sockfd, newsockfd, portno, n;
	pid_t pid;
	struct sockaddr_in serv_addr, clt_addr;
	socklen_t addrlen;
	char buffer[256];

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <port>\n", argv[0]);
		return 1;
	}
	portno = atoi(argv[1]);

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
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

	for (;;) {
		printf("wait on port %d...\n", portno);
		addrlen = sizeof(clt_addr);
		newsockfd = accept(sockfd, (struct sockaddr*) &clt_addr, &addrlen);
		if (newsockfd < 0)
			syserr("can't accept");

		if (!(pid = fork())) {
			close(sockfd);
			doftp(newsockfd);
			close(newsockfd);
			exit(0);
		}
	}
	close(sockfd);
	return 0;
}

