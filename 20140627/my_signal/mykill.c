/*************************************************************************
	> File Name: mykill.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 26 Jun 2014 09:58:40 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int pid = atoi(argv[1]);
	while(1)
	{
		kill((pid_t)pid, 2);
		kill((pid_t)pid, 3);
		sleep(2);
	}
	

}
