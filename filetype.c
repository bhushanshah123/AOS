#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main (int argc, char*argv[])
{	int i;
	if (argc<=1)
	{ printf("Insuffitient Argument");
	exit(0);	
	}
	struct stat s;
	stat (argv[i],&s);
	if (S_ISREG(s.st_mode))
		printf("Regular File");
	else if (S_ISDIR(s.st_mode))
		printf("Directory File");
	else if (S_ISFIFO(s.st_mode))
		printf("Fifo File");
	else if (S_ISSOCK(s.st_mode))
		printf("SOCKET File");
	else if (S_ISBLK(s.st_mode))
		printf("Symbolic File");
	else if (S_ISCHR(s.st_mode))
		printf("Character File");
	else if (S_ISLNK(s.st_mode))
		printf("LINK File");

	return 0;
	

}
