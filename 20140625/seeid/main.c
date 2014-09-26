/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 24 Jun 2014 09:35:40 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("pid: %u \n ppid: %u \n uid: %u \n gid:%u \n euid:%u",
			getpid(), getppid(), getuid(), getgid(), geteuid());

}
