/*************************************************************************
	> File Name: my_fork.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 04:11:43 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	printf("hello \n");
	int sun_id;
	long int iret;
	iret = (long int)fork();

	printf("world\n");
	if(iret == 0)
	{
		printf("iret fork: %d, pid :%d, ppid:%d\n", iret, sun_id = getpid(), getppid());
		printf("child");
		sleep(10);
	}
	else
	{
		printf("father");
		iret = (long int)wait(sun_id);
		printf("iret fork: %d, pid :%d, ppid:%d\n", iret, getpid(), getppid());
	}
	return  0;
}

