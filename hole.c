#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
	char b1[]="Hello Everyone";
	char b2[]="Good Bye";
	int fd;
	fd=open("b1.txt",O_WRONLY|O_TRUNC|O_CREAT,0666);
	write(fd,b1,strlen(b1));
	lseek(fd,100,SEEK_CUR);
	write(fd,b2,strlen(b2));
	close (fd);
	return 0;
}

