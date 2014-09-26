/*************************************************************************
	> File Name: my_fork.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 26 Jun 2014 10:05:56 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void my_handler(int num)
{
	printf("sigNO: %d \n", num);
}

int main()
{
	if(fork() > 0)
	{

		signal(17, my_handler);
		while(1);
	}
	else
	{
		sleep(5);
			exit(0);
	
	}
}
