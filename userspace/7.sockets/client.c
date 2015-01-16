#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	int sock_desc = 0, ret = 0, i = 0;
	struct sockaddr_in server;
	char reply[1024];

	/* Create a socket */
	sock_desc = socket(AF_INET, SOCK_STREAM, 0);
	if(sock_desc < 0) {
		fprintf(stderr, "Error!! socket() failed with error code: %d\n", sock_desc);
		exit(EXIT_FAILURE);
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(5555);

	/* Set address in socket by converting text to binary format */
	if((ret = inet_pton(AF_INET, argv[1], &server.sin_addr)) <= 0) {
		fprintf(stderr, "Error!! inet_pton() failed with error code: %d\n", ret);
		exit(EXIT_FAILURE);
	}

	if((ret = connect(sock_desc, (struct sockaddr *)&server, sizeof(server))) < 0) {
		fprintf(stderr, "Error!! connect() failed with error code: %d\n", ret);
		exit(EXIT_FAILURE);
	}

	if((ret = recv(sock_desc, reply, 1024, 0)) < 0) {
		fprintf(stderr, "Error!! recv() failed with error code: %d\n", ret);
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < strlen(reply) - 1; i++) {
//		printf("Server: %c", reply[i]);
	}
		printf("Server: %s\n", reply);
//		puts(reply);

	exit(EXIT_SUCCESS);
}
