#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <dirent.h>
#include<string.h>

int main(int argc, char * argv[])
{
	DIR *d;
	struct dirent *dr;
	char t[100];
	d=opendir(".");
	if (argc<=1)
	{
		printf("Insuffitient Argument");
	exit(0);
	}
	while (dr=readdir(d))
	{
		strncpy(t,dr->d_name,strlen(argv[1]));
		if (strcmp(t,argv[1]==0))
			printf("%s\t",dr->d_name);
	}
	closedir(d);x
	return 0;
}



	
		
	
	
