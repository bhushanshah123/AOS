#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(int argc, char * argv[])
{
	struct stat s;
	int i;
	if (argc<=1)
	{
		printf("Insuffitient argument");
		exit(0);
	}
	for (i=1;i<=argc;i++)
	{		
		stat (argv[i],&s);
		printf("\n %s \t %d",argv[i],s.st_ino);
	}
	return 0;
}
