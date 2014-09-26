/*************************************************************************
	> File Name: my_ls.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 11:23:14 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	DIR * pDir;
	struct dirent* myent;
	if(argc == 1)
	{
		pDir = opendir(".");
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
	while((	myent = readdir(pDir))!= NULL)
	printf("size:%d\ntype:%c\nname:%s\n", myent->d_reclen, myent->d_type,
			myent->d_name);


	return 0;
}
