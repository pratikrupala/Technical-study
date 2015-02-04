#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

#include "myhdr.h"

int main(void)
{
	int cont = 1;
	int msgid = 0;
	struct mystruct msgst;
	int msg_id = 0;

	if((msgid = msgget((key_t)5555, IPC_CREAT)) == -1) {
		fprintf(stderr, "Failed to create message queue with error: %d.\n", errno);
		exit(EXIT_FAILURE);
	}

	while(cont) {
		if((msgrcv(msgid, (void *)&msgst, BUF_SIZE, msg_id, 0)) == -1) {
			fprintf(stderr, "Failed to receive message from message queue with error: %d.\n", errno);
	                exit(EXIT_FAILURE);
		}
		printf("Sender has sent: %s\n", msgst.buf);
		if((strncmp(msgst.buf, "done", 4)) == 0) {
			cont = 0;
		}
	}

	if((msgctl(msgid, IPC_RMID, 0)) == -1) {
		fprintf(stderr, "Failed to delete message queue with error: %d.\n", errno);
                exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
