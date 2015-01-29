#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 20

int main(void)
{
	int fd[2];
	char *str = "Hello World";
	char buf[BUF_SIZE + 1];
	pid_t new_proc;

	memset(buf, '\0', BUF_SIZE);

	if((pipe(fd)) != 0) {
		printf("Failed to create a pipe.\n");
		exit(EXIT_FAILURE);
	}

	if((new_proc = fork()) == (pid_t)-1) {
		printf("Failed to creat a child process.\n");
		exit(EXIT_FAILURE);
	}
	
	if(new_proc == 0) {
		sprintf(buf, "%d", fd[0]);
		(void)execl("consumer", "consumer", buf, (char *)0);
		exit(EXIT_FAILURE);
	} else {
		if((write(fd[1], str, strlen(str))) == 0) {
                        printf("Parent failed to write.\n");
                        exit(EXIT_FAILURE);
                } else {
                        printf("Parent written to a pipe: %s\n", str);
                }
	}

	exit(EXIT_SUCCESS);
}
