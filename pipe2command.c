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
{	char s[80];
	int p[2],n;
	pipe(p);
	n=fork();
	if (n==0){
		close(p[0]);
		close(1);
		dup(p[1]);
		close(p[1]);
		execlp("ls","ls","-l",NULL);
		}
	else{wait();
		printf("\n In Parent\n");	
		while(read(p[0],s,80)){
			printf("%s",s);}
		}
	return 0;
}

		
