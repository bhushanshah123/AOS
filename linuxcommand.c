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
	int p[2],n;
	pipe(p);
	n=fork();
	if (n==0){
		close (p[0]);
		dup(p[1]);
		close(p[1]);
		execlp("ls","ls","-l",NULL);	
	}
	
	else {
		close(p[1])	;
		close(0);
		dup (p[0]);
		close (p[0]);
		execlp("wc","wc","-l",NULL);
	}
return 0;	
}
		
	
	
	
	
