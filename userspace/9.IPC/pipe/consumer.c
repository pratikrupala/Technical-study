#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 20

int main(int argc, char *argv[])
{
	int fd;
	char buf[BUF_SIZE + 1];

	memset(buf, '\0', BUF_SIZE);
	sscanf(argv[1], "%d", &fd);

	if((read(fd, buf, BUF_SIZE)) == 0) {
		printf("Consumer failed to read.\n");
		exit(EXIT_FAILURE);
	}

	printf("Consumer read: %s\n", buf);

	exit(EXIT_SUCCESS);
}
