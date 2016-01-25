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

#define MAXLINE 256
#define MAXSIZE 512

#define LSREMOTE	"ls-remote"
#define LSLOCAL		"ls-local"
#define GET			"get"
#define PUT			"put"
#define EXIT		"exit"

void syserr(char* msg) {
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

int main(int argc, char* argv[]) {
	int sockfd, portno, n, size;
	uint32_t filelen;
	struct hostent* server;
	struct sockaddr_in serv_addr;
	char buffer[256], *f, *arg1, *arg2, *filename;
	FILE * fp;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
		return 1;
	}
	server = gethostbyname(argv[1]);
	if (!server) {
		fprintf(stderr, "ERROR: no such host: %s\n", argv[1]);
		return 2;
	}
	portno = atoi(argv[2]);

	// create socket
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0)
		syserr("can't open socket");
	printf("create socket...\n");

	// initialize serv_addr
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr = *((struct in_addr*) server->h_addr);
	serv_addr.sin_port = htons(portno);

	// connect to server
	if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
		syserr("can't connect to server");
	printf("Connection to %s:%d established. Now awaiting commands...\n", inet_ntoa(serv_addr.sin_addr), portno);

	arg1 = malloc(sizeof(char) * MAXLINE);
	arg2 = malloc(sizeof(char) * MAXLINE);

	while(1) {
		// get command
		printf("PLEASE ENTER MESSAGE: ");
		fgets(buffer, MAXLINE, stdin);
		n = strlen(buffer);
		if (n > 0 && buffer[n - 1] == '\n')
			buffer[n - 1] = '\0';

		// arg1 contains first part of command
		strcpy(arg1, strtok(buffer, " "));

		// ls-remote
		if (!strcmp(arg1, LSREMOTE)) {
			// send the request to do ls-remote
			n = send(sockfd, buffer, MAXSIZE, 0);
			if (n < 0)
				syserr("can't send to server");
			printf("send...\n");

			// receive the size of the file
			n = recv(sockfd, &filelen, sizeof(int), 0);
			if (n < 0)
				syserr("can't receive from server");
			filelen = ntohl(filelen);

			// receive the file
			f = malloc(filelen);
			n = recvall(sockfd, f, &filelen);
			filename = "ls-remote.txt";
			fp = fopen(filename, "wb");
			fwrite(f, 1, filelen, fp);
			fclose(fp);

			// print the content of ls-remote on client
			strcpy(arg1, "cat ");
			strcat(arg1, filename);
			printf("Files at the server (%s):\n", inet_ntoa(serv_addr.sin_addr));
			system(arg1);
		}
		// ls-local
		else if (!strcmp(arg1, LSLOCAL)) {
			// do ls-local and print the content of ls-local on client
			system("ls >ls-local.txt");
			printf("Files at the client:\n");
			system("cat ls-local.txt");
		}
		// get filename
		else if (!strcmp(arg1, GET)) {
			// get the second argument, which is the file name
			filename = strtok(NULL, " ");
			if (!filename) {
				printf("requires 1 more parameters for 'get'\n");
				continue;
			}

			// send get file request to server
			n = send(sockfd, arg1, MAXLINE, 0);
			if (n < 0)
				syserr("can't send to server");
			n = send(sockfd, filename, MAXLINE, 0);
			if (n < 0)
				syserr("can't send to server");

			// receive the size of the file
			recv(sockfd, &filelen, sizeof(int), 0);
			if (!filelen) {
				printf("No such file on the remote directory\n");
				continue;
			}
			filelen = ntohl(filelen);

			// receive the file
			f = malloc(filelen);
			n = recvall(sockfd, f, &filelen);
			fp = fopen(filename, "wb");
			fwrite(f, 1, filelen, fp);
			fclose(fp);
			printf("Retrieve '%s' from remote server: successful\n", filename);
		}
		// put filename
		else if (!strcmp(arg1, PUT)) {
			// get the second argument, which is the file name
			filename = strtok(NULL, " ");
			if (!filename) {
				printf("requires 1 more parameters for 'put'\n");
				continue;
			}
			// send put file request to server
			n = send(sockfd, arg1, MAXLINE, 0);
			if (n < 0)
				syserr("can't send to server");
			n = send(sockfd, filename, MAXLINE, 0);
			if (n < 0)
				syserr("can't send to server");

			fp = fopen(filename, "rb");
			if (!fp) {
				printf("No such file on the local directory\n");
				filelen = 0;
				filelen = htonl(filelen);
				n = send(sockfd, &filelen, sizeof(int), 0);
				continue;
			}
			fseek(fp, 0, SEEK_END);
			filelen = ftell(fp);
			rewind(fp);
			filelen = htonl(filelen);

			// send the size of the file
			n = send(sockfd, &filelen, sizeof(int), 0);
			if (n < 0)
				syserr("can't send to server");

			// send the file
			f = (char *) malloc((filelen + 1) * sizeof(char));
			fread(f, filelen, 1, fp);
			f[filelen+1] = '\0';
			fclose(fp);
			filelen = ntohl(filelen);
			n = sendall(sockfd, f, &filelen);
			if (n < 0)
				syserr("can't send to server");
			n = recv(sockfd, f, MAXSIZE, 0);
			if (n < 0)
				syserr("can't receive from server");
			printf("Upload '%s' to remote server: successful\n", filename);
		}
		// exit
		else if (!strcmp(arg1, EXIT)) {
			// send command to server
			n = send(sockfd, arg1, MAXLINE, 0);
			if (n < 0)
				syserr("can't send to server");
			printf("Connection to server %s:%d terminated. Bye now!\n", inet_ntoa(serv_addr.sin_addr), portno);
			break;
		} else {
			printf("unrecognized command, please try again.\n");
		}
	}
	free(arg1);
	free(arg2);
	close(sockfd);
	return 0;
}
