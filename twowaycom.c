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
	int p1[2],p2[2],n;
	char s[80];
	pipe(p1);
	pipe(p2);

	n=fork ();
	if (n!=0){
		close(p1[0]);
		close(p2[1]);
		printf("\nserver write-> Hello from Server\n");
		write(p1[1],"Hello from server",18);
		read(p2[0],s,80);
		printf("\n serever read->%s",s);
	}

	else{
			close(p1[1]);
			close(p2[0]);
			read (p1[0],s,80);
			printf("\n client read->%s\n",s);
			printf("\n client write-> Hello from client\n");		
			write (p2[1],"Hello from Client",20);
			}
	return 0;
}
			
		


