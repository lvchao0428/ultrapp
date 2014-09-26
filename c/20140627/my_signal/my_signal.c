/*************************************************************************
	> File Name: my_signal.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 26 Jun 2014 09:35:22 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void my_handler(int num)
{
	printf("sig num: %d \n", num);
}

int main()
{
	signal(2, my_handler);
	signal(3, my_handler);
	signal(9, my_handler);
		
	printf("hello\n");
	while(1)
	{
		printf("hello\n");
		sleep(1);
	}
}

