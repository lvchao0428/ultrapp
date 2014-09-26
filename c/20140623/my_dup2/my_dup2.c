/*************************************************************************
	> File Name: my_dup2.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 23 Jun 2014 03:21:51 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd_wr;

	fd_wr = open("a.out", O_WRONLY | O_CREAT);
	dup2(fd_wr, 1);
	close(fd_wr);

	printf("helloworld");
	return  0;
}
