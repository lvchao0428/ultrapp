/*************************************************************************
	> File Name: son.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 04:57:52 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
	if(pid == 0)
	{
		while(1);
		
	}
	else
	{
		exit(10);
	}

}
