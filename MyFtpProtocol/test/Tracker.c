// gcc -pthread -std=gnu99 Tracker.c -o tracker

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
#include <arpa/inet.h>

#define MAXLINE 255
#define MAXSIZE 511
#define DEFSIZE 8

#define LIST	"list"
#define EXIT	"exit"
#define UPDATE	"update"

pthread_mutex_t peer_mutex;

typedef struct { struct sockaddr_in peer_addr; int port; } Peer;

typedef struct Node{
	char* filename;
	char* ip;
	int port;
	struct Node* next;
} Node;

typedef struct {
	int size;
	Node* head;
} List;

void node_init(Node* node, char* s, char* ip, int port) {
	node->filename = (char*)malloc(MAXLINE*sizeof(char));
	node->ip = (char*)malloc(MAXLINE*sizeof(char));
	node->next = NULL;

	strcpy(node->filename, s);
	strcpy(node->ip, ip);
	node->port = port;
}

void node_free(Node* node) {
	free(node->filename);
	node->filename = NULL;
	free(node->ip);
	node->ip = NULL;
	node->next = NULL;
	free(node);
	node = NULL;
}

List* list;

void list_add(List* list, Node* node) {
	node->next = list->head;
	list->head = node;
	list->size++;
}

void init(List* list) {
	list->head = NULL;
	list->size = 0;
}

void syserr(char *msg) { perror(msg); exit(-1); }

int sendall(int s, char *buf, int *len) {
	int total = 0, bytesleft = *len, n;
	while (total < *len) {
		n = send(s, buf + total, bytesleft, 0);
		if (n == -1) break;
		total += n; bytesleft -= n; }
	*len = total;
	return n == -1 ? -1 : 0; // return -1 on failure, 0 on success
}

int recvall(int s, char *buf, int *len) {
	int total = 0, bytesleft = *len, n;
	while (total < *len) {
		n = recv(s, buf + total, bytesleft, 0);
		if (n == -1) break;
		total += n; bytesleft -= n; }
	*len = total;
	return n == -1 ? -1 : 0; // return -1 on failure, 0 on success
}

void *dop2p(void* peer) {
	FILE *fp;
	Peer* p = (Peer*)peer;
	uint32_t filelen;
	int n, sockfd = p->port;
	char rq[MAXLINE], *buffer, *f;

	if ((recv(sockfd, &n, sizeof(int), 0)) < 0) { syserr("can't receive port number from client"); exit(0);	}
	p->port = ntohl(n);
	// receive the size of the file
	if (recv(sockfd, &filelen, sizeof(int), 0) < 0) syserr("can't receive from server");
	filelen = ntohl(filelen);
	// receive the file
	f = (char*)malloc(filelen*sizeof(char));
	if (recvall(sockfd, f, &filelen) < 0) syserr("can't receive from server");
	char *s = f, *e = f;
	while (e < f + filelen && *e != '\0') {
		if (*e == '\n') {
			*e = '\0';
			int found = 0;
			pthread_mutex_lock(&peer_mutex);
			Node* node;
			node = (Node*)malloc(sizeof(Node));
			node_init(node, s, inet_ntoa(p->peer_addr.sin_addr), p->port);
			list_add(list, node);

			pthread_mutex_unlock(&peer_mutex);
			s = e+1;
		}
		e++;
	}
	free(f);

	buffer = (char*)malloc(MAXLINE*sizeof(char));
	while (1) {
		memset(rq,0, MAXLINE*sizeof(char));

		if ((recv(sockfd, rq, MAXLINE, 0)) < 0) { syserr("can't receive from client"); exit(0); }

		if (!strcmp(rq, LIST)) {
			// execute ls on command line and write outcome into a file
			pthread_mutex_lock(&peer_mutex);
			fp = fopen("list.txt", "wb");
			Node* cur = list->head;
			n = 0;
			while (cur) {
				memset(buffer, 0, sizeof(buffer));
				sprintf(buffer, "[%d] %s, %s:%d\n", n++, cur->filename, cur->ip, cur->port);
				cur = cur->next;
				int k = 0;
				while (*(buffer+k++) != '\n');
				fwrite(buffer, 1, k, fp);
			}
			fclose(fp);
			fp = fopen("list.txt", "rb"); fseek(fp, 0, SEEK_END);
			filelen = ftell(fp); rewind(fp);
			filelen++;
			filelen = htonl(filelen);
			//notify client the size of the file
			if (send(sockfd, &filelen, sizeof(int), 0) < 0) syserr("can't send to client");
			//send file to the client
			filelen = ntohl(filelen);
			buffer = (char *)realloc(buffer, (filelen) * sizeof(char));
			memset(buffer, 0, filelen);
			fread(buffer, filelen-1, 1, fp);
			fclose(fp);
			pthread_mutex_unlock(&peer_mutex);
			buffer[filelen-1] = '\0';
			if (sendall(sockfd, buffer, &filelen) < 0) syserr("can't send to client");
		}
		else if (!strcmp(rq, EXIT)) {
			pthread_mutex_lock(&peer_mutex);
			if (list->head) {
				Node* cur = list->head;
				while (cur->next) {
					if (!strcmp(cur->next->ip, inet_ntoa(p->peer_addr.sin_addr)) && cur->next->port == p->port) {
						Node* tmp = cur->next;
						cur->next = cur->next->next;
						node_free(tmp);
						list->size--;
					} else
						cur = cur->next;
				}
				if (!strcmp(list->head->ip, inet_ntoa(p->peer_addr.sin_addr)) && list->head->port == p->port) {
					Node* tmp = list->head;
					list->head = list->head->next;
					node_free(tmp);
					list->size--;
				}
			}
			pthread_mutex_unlock(&peer_mutex);
			printf("Peer %s:%d has left.\n", inet_ntoa(p->peer_addr.sin_addr), p->port);
			break;
		} else if (!strcmp(rq, UPDATE)) {
			if ((recv(sockfd, rq, MAXLINE, 0)) < 0) { syserr("can't receive from client"); exit(0); }
			char* s = (char*)malloc(MAXLINE*sizeof(char));
			strcpy(s, rq);
			s[strlen(s)] = '\0';
			pthread_mutex_lock(&peer_mutex);
			Node* node;
			node = (Node*)malloc(sizeof(Node));
			node_init(node, s, inet_ntoa(p->peer_addr.sin_addr), p->port);
			list_add(list, node);
			pthread_mutex_unlock(&peer_mutex);
		}
		else {
			pthread_mutex_lock(&peer_mutex);
			if (list->head) {
				Node* cur = list->head;
				while (cur->next) {
					if (!strcmp(cur->next->ip, inet_ntoa(p->peer_addr.sin_addr)) && cur->next->port == p->port) {
						Node* tmp = cur->next;
						cur->next = cur->next->next;
						node_free(tmp);
						list->size--;
					} else
						cur = cur->next;
				}
				if (!strcmp(list->head->ip, inet_ntoa(p->peer_addr.sin_addr)) && list->head->port == p->port) {
					Node* tmp = list->head;
					list->head = list->head->next;
					node_free(tmp);
					list->size--;
				}
			}
			pthread_mutex_unlock(&peer_mutex);
			printf("Peer %s:%d has left.\n", inet_ntoa(p->peer_addr.sin_addr), p->port);
			break;
		}

	}
	free(buffer);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	pid_t pid;
	socklen_t addrlen;
	int sockfd, newsockfd, portno, n;
	char buffer[MAXLINE];
	struct sockaddr_in serv_addr, clt_addr;

	if (argc == 1)
		portno = 5000;
	else if (argc == 2)
		portno = atoi(argv[1]);
	else { fprintf(stderr, "Usage: %s <port>\n", argv[0]); return 1; }

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) syserr("can't open socket");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) syserr("can't bind");
	listen(sockfd, 5);

	list = (List*)malloc(sizeof(List));
	init(list);

	for (;;) {
		printf("wait on port %d...\n", portno);
		addrlen = sizeof(clt_addr);
		newsockfd = accept(sockfd, (struct sockaddr*) &clt_addr, &addrlen);
		if (newsockfd < 0)
			syserr("can't accept");
		Peer* p = (Peer*)malloc(sizeof(Peer));
		p->peer_addr = clt_addr;
		p->port = newsockfd;
		pthread_t tid;
		pthread_create(&tid, NULL, dop2p, (void *)p);
	}
	close(sockfd);
	return 0;
}

