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
	int fd1,fd2;
	fd1=open("output.txt",O_WRONLY|O_CREAT,0666);
	printf("\n Normal Output");
	fflush(stdout);
	fd2=dup(1);
	dup2(fd1,1);
	printf("\n1:ABC");
	printf("\n2:XYZ");
	fflush(stdout);
	close (fd1);
	dup2(fd2,1);
	printf("\nAgain Normal");
	return 0;
}
		
	
	
	
