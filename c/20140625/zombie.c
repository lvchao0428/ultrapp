/*************************************************************************
	> File Name: zombie.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 05:02:51 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();

	if(pid == 0 )
	{
		exit(10);
	}
	else
	{
		sleep(100);
	}
}
	

