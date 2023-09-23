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

int main()
{
	char fn[50],s[500];
	struct passwd *pw;
	struct group *gr;
	struct stat s1;
	printf("\n Enter file name:");
	gets (fn);
	stat (fn,&s1);
	if (S_ISREG(s1.st_mode))
		printf("Regular File");
	 if (S_ISDIR(s1.st_mode))
		printf("Directory File");
	 if (S_ISFIFO(s1.st_mode))
		printf("Fifo File");
	 if (S_ISSOCK(s1.st_mode))
		printf("SOCKET File");
	 if (S_ISBLK(s1.st_mode))
		printf("Symbolic File");
	 if (S_ISCHR(s1.st_mode))
		printf("Character File");
	 if (S_ISLNK(s1.st_mode))
		printf("LINK File");
	
	printf("\n file Permission:");     //USer Permission
	printf((s1.st_mode & S_IRUSR)?"r":"-");
	printf((s1.st_mode & S_IWUSR)?"w":"-");
	printf((s1.st_mode & S_IXUSR)?"x":"-");

	printf((s1.st_mode & S_IRGRP)?"r":"-");	//Group Permission
	printf((s1.st_mode & S_IWGRP)?"w":"-");	
	printf((s1.st_mode & S_IXGRP)?"x":"-");	
	
	printf((s1.st_mode & S_IROTH)?"r":"-");	//Other Permission
	printf((s1.st_mode & S_IWOTH)?"w":"-");	
	printf((s1.st_mode & S_IXOTH)?"x":"-");	

	printf("\n INODE NO:%d",s1.st_ino);
	printf("\n No of Link: %d",s1.st_nlink);
	printf("\n File Size: %d",s1.st_size);	

	strcpy(s,ctime(&s1.st_atim));
	strcpy(s,ctime(&s1.st_mtim));
	strcpy(s,ctime(&s1.st_ctim));
	printf("\n Accesses time:%s",s);
	printf("\n Modified time:%s",s);
	printf("\n Creation time:%s",s);

	printf("\n user ID:%d",s1.st_uid);
	pw=getpwuid(s1.st_uid);
	printf("\n user name:%s",pw->pw_name);

	printf("gid->%d",s1.st_gid);
	gr=getgrgid(s1.st_gid);
	printf("\n group name:%s",gr->gr_name);
	return 0;
}











