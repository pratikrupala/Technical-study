#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

int main(void)
{
	pid_t child;

	child = fork();

	if(child >= 0) { /* fork successful  */
		if(child == 0) { /* This is child process */
			printf("Child: process id:[%d] and parent id:[%d]\n", getpid(), getppid());
		} else { /* This is parent */
			printf("Parent: process id:[%d] and child id:[%d]\n", getpid(), child);
		}
	} else { /* fork call failed */
	exit(EXIT_FAILURE);
	}

	return 0;
}
