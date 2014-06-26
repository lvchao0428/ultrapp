/*************************************************************************
	> File Name: my_exec.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 02:20:08 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

int main(int argc, char **argv)
{
	char buf[100];
	printf("execl begin!\n");
	execl("/bin/ls", "ls", "-l", NULL);
	printf("execl end!\n");
	

	return 0;
}

