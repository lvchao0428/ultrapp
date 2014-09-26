/*************************************************************************
	> File Name: my_ls.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 11:23:14 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>


void formate_time(char * t);
void mode_to_str(mode_t md, char * str);
int main(int argc, char **argv)
{
	DIR * pDir;
	struct stat mystat;
	struct dirent* myent;
	char str_mode[11];
	mode_t md;
	char* ftime;
	char ab_path[100];
	struct passwd* puid;
	struct group* pgid;
	if(argc == 1)
	{
		pDir = opendir(".");
		strcpy(ab_path, getcwd(NULL,0));
	}
	else
	{
		pDir = opendir(argv[1]);
	}
	if(pDir == NULL)
	{
		perror("open dir fail: ");
		exit(-1);
	}
	printf("mode,ino, uid, gid, size, time, name\n");
	while((	myent = readdir(pDir))!= NULL)
	{	
		memset(&mystat,0,sizeof(mystat));
		if(argc != 1)
		{
			strcpy(ab_path, argv[1]);
		}
		if(find_argv_rear(ab_path))
			strcat(ab_path, "/");
		strcat(ab_path, myent->d_name);
		printf("ab_path:%s\n", ab_path);
		stat(ab_path, &mystat);
		memset(str_mode, 0, 11);
		mode_to_str(mystat.st_mode , str_mode);
			
		ftime = ctime(&mystat.st_atime);
		//ftime = ctime("");
		formate_time(ftime);
		puid = getpwuid(mystat.st_uid);
		pgid = getgrgid(mystat.st_gid);
		if(strncmp(myent->d_name, ".", 1)!=0)
		{
		printf("%10s %3d %-5s %-5s %-5d %-10s %s\n", 
				str_mode,
				mystat.st_nlink,
				puid->pw_name, 
				pgid->gr_name, 
				mystat.st_size, 
				ftime+4, 
				myent->d_name);
		}
	}


	return 0;
}

void formate_time(char * t)
{
	char *p = t;
	while(*p++);
	while((*p)!= ':')p--;
	(*p) = '\0';
}

int find_argv_rear(char *c)
{
	char *p = c;
	while(*p!='\0')p++;
	if(*(p-1)=='/')
		return 0;
	else
		return 1;
}

void mode_to_str(mode_t md, char * str)
{
	strcpy(str,"----------");
	if(S_ISDIR(md))
	{
		str[0] = 'd';
	}
	 
	if(md & S_IRUSR)
	{
		str[1] = 'r';
	}
	if(md & S_IWUSR)
	{
		str[2] = 'w';
	}
	if(md & S_IXUSR)
	{
		str[3] = 'x';
	}
	if(md & S_IRGRP)
	{
		str[4] = 'r';
	}
	if(md & S_IWGRP)
	{
		str[5] = 'w';
	}
	if(md & S_IXGRP)
	{
		str[6] = 'x';
	}
	if(md & S_IROTH)
	{
		str[7] = 'r';
	}
	if(md & S_IWOTH)
	{
		str[8] = 'w';
	}
	if(md & S_IXOTH)
	{
		str[9] = 'x';
	}
}
