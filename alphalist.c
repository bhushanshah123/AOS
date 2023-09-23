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

int main ()
{
	char dn[50][50],t[50];
	int n=0,i,j;
	struct dirent *dr;
	DIR *d;
	struct stat s;
	d=opendir(".");
	while (dr=readdir(d))
	{
		stat (dr->d_name,&s);
		if (S_ISDIR(s.st_mode))
		{
			strcpy(dn[n],dr->d_name);
			n++;
		}
	}
	for(i=0;i<n;i++)
		for (j=0;j<n;j++)
	if (strcmp(dn[i],dn[j])<0)
	{
		strcpy(t,dn[i]);
		strcpy(dn[i],dn[j]);		
		strcpy(dn[j],t);
	}
	printf("\n list of subdirectories in a assending order:\n");
		for (i=0;i<n;i++)
		printf("%s\n",dn[i]);
	closedir(d);
	return 0;
}
		
	
	

