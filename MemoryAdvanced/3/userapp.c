#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("/dev/mychardev", O_RDWR);
	perror("fd");
}
