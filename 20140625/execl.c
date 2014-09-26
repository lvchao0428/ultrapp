/*************************************************************************
	> File Name: execl.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 03:11:21 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	printf("execl begin:\n");

	execl("/bin/ls", "ls", "-l", NULL);
	printf("execl end!\n");

	return 0;
}
