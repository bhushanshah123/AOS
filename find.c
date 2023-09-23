#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main ()
{
	char s[100];
	int fd;
	printf("\n Enter file name:");
	gets(s);
	fd=open(s,O_RDONLY);
	if (fd<0)
		printf("\n File Not Found");
	else
		printf("\n File is present");
	return 0;	
}
