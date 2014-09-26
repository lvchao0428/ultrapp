/*************************************************************************
	> File Name: my_rmdir.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 10:19:47 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int x;
	
	x = rmdir(argv[1]);
	if(x)
	{
		perror("cannot remove the folder.");
	}
		
	return 0;
}

