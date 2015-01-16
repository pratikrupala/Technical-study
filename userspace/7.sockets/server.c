#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void)
{
	int sock_desc = 0, client_desc = 0, ret = 0;
	struct sockaddr_in server;
	char *str;

	/* Create a socket on server side with socket() API */
	sock_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_desc < 0) { /* Socket creation failed */
		fprintf(stderr, "Error!! socket() failed with error code: %d\n", sock_desc);
		exit(EXIT_FAILURE);
	}

	/* Fill up server info */
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(5555);

	/* Now bind() */
	if((ret = bind(sock_desc, (struct sockaddr *)&server, sizeof(server))) < 0) {
		fprintf(stderr, "Error!! bind() failed with error code: %d\n", ret);
		exit(EXIT_FAILURE);
	}

	/* Now Listen to port for maximum 10 connections */
	if((ret = listen(sock_desc, 10)) < 0) {
		fprintf(stderr, "Error!! listen() failed with error code: %d\n", ret);
                exit(EXIT_FAILURE);
	}

	/* Accept the connections from client */
	while((client_desc = accept(sock_desc, (struct sockaddr *)NULL, NULL))) {
		printf("New connection accepted\n");
		str = "Hi there!! I accepted your connection";
		if((ret = send(client_desc, str, strlen(str), 0)) < 0) {
			fprintf(stderr, "Error!! send() failed with error code: %d\n", ret);
			exit(EXIT_FAILURE);
		}
	}
	
	if(client_desc < 0) {
		fprintf(stderr, "Error!! accept() failed with error code: %d", client_desc);
                exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
