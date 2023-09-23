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
	int n;
	struct stat s1;
	DIR *d;
	struct dirent *dr;
	printf("\n Enter SIZE:");
	scanf("%d",&n);
	d=opendir(".");	
	while (dr=readdir(d))
	{
		stat (dr->d_name,&s1);
		if (s1.st_size>n)
			printf("%s\n",dr->d_name);
	}
	close(d);
	return 0;
}

