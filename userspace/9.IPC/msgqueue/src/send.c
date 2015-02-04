#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

#include "myhdr.h"

int main(void)
{
	int cont = 1;
	char buffer[BUF_SIZE];
	int msgid = 0;
	struct mystruct msgst;

	memset(buffer, '\0', BUF_SIZE);

	if((msgid = msgget((key_t)5555, 0666 | IPC_CREAT)) == -1) {
		fprintf(stderr, "Failed to create message queue with error: %d.\n", errno);
		exit(EXIT_FAILURE);
	}

	while(cont) {
		printf("Enter input:");
		fgets(buffer, BUF_SIZE, stdin);

		msgst.my_id = 1;
		strncpy(msgst.buf, buffer, BUF_SIZE);
		if((msgsnd(msgid, (void *)&msgst, BUF_SIZE, 0)) == -1) {
			fprintf(stderr, "Failed to send message to message queue, error: %d.\n", errno);
                	exit(EXIT_FAILURE);
		}

		if((strncmp(buffer, "done", 4)) == 0) {
			cont = 0;
		}
	}

	exit(EXIT_SUCCESS);
}
