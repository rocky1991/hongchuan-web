#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char * argv[]) {
	int fd; 

	unsigned char byte;
	int bytes_read;
	int zeros, total;
	char *path;

	if (argc < 2) {
		printf("usage: reader filename\n");
		return -1;
	}
	path = argv[1];
	printf("opening %s \n", path);
	fd = open(path, O_RDONLY);
	printf("fd is %d\n", fd);
	zeros = 0;
	total = 0;
	
	while (1) {
		bytes_read = read(fd, &byte, 1);
		if (bytes_read != 1) {
			printf("all done, zeros = 0x%x(%d), total = 0x%x(%d)\n", zeros,zeros,total, total);
			return 0;
		}
		if (0 == byte - '0')
			zeros++;
		total++;
	}
	return 0;
}
