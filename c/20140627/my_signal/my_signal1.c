/*************************************************************************
	> File Name: my_signal1.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 26 Jun 2014 09:53:08 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ss(int num)
{
	printf("kkk:%d\n", num);
}

int main()
{
	signal(2, ss);
	signal(3, ss);

	while(1)
	{
		printf("hello\n");
		sleep(1);
	}


	return 0;
}
