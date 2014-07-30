/*************************************************************************
	> File Name: my_mkdir.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 10:05:00 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int x;
	x = mkdir("my_folder" , 0);
	if(x)
	{
		perror("cannot create the file.");
	}


	return 0;
}
