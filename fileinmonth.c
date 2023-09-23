#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<string.h>
#include<dirent.h>


int main()
{
	char m[50];
	char s[500];
	struct stat s1;
	DIR *d;
	struct dirent *dr;
	printf("\n Enter Month:");
	gets(m);
	d=opendir(".");	
	while (dr=readdir(d))
	{
		stat (dr->d_name,&s1);
		strcpy(s,ctime (& s1.st_ctim));
		if (strstr(s,m))
			printf("%s",dr->d_name);
	}
	close(d);
	return 0;
}



	

