/*************************************************************************
	> File Name: wait.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 04:59:43 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t pid = fork();
	if(pid == 0)
	{
		exit(10);
	}
	else
	{
		wait(NULL);
		sleep(20);
	}

	return 0;	
}
