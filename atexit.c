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
void b1(void);
void b2(void);
void b3(void);

int main()
{
	printf("\nI am in Main");
	atexit(b1);
	atexit(b2);
	atexit(b1);
	atexit(b3);
	printf("\n I am end of MAin");
	return 0;
}

void b1(void)
{
	printf("\n i am b1");
}

void b2(void)
{
	printf("\n i am b2");
}

void b3(void)
{
	printf("\n i am b3");
}



