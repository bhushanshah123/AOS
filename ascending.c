#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char * argv[])
{
	char t[100];
	struct stat s1,s2;
	int i,j;
	if (argc<=1)
	{
		printf("Insuffitient Argument");
		exit(0);
	}
	for (i=1;i<=argc;i++)
		for(j=j+1;j<=argc;j++)
		{
			stat(argv[i],&s1);
			stat(argv[j],&s2);			
			if (s1.st_size> s2.st_size)
			{strcpy(t,argv[i]);
			strcpy(argv[i],argv[j]);
			strcpy(argv[j],t);
			}
		}
	printf("File in ascending order ");
	for (i=1;i<=argc;i++)
	{
		stat(argv[i],&s1);
		printf("\n %s \t %d",argv[i],s1.st_size);
	}
	return 0;
}






	
