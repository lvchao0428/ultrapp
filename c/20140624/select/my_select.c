/*************************************************************************
	> File Name: my_select.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 24 Jun 2014 03:45:02 AM EDT
 ************************************************************************/
#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>

int main()
{
	int fd1, fd2, n_ready;
	char buf[1024];
	fd1 = open("1.txt", O_RDONLY);
	fd2 = open("2.txt", O_RDONLY);
	fd_set fd_read, fd_ready;
	FD_ZERO(&fd_read);
	FD_SET(0, &fd_read);
	FD_SET(fd1, &fd_read);
	FD_SET(fd2, &fd_read);
	struct timeval tm;
	while(1)
	{
		tm.tv_sec = 3;
		tm.tv_usec = 0;
		fd_ready = fd_read;
		n_ready = select(1024, &fd_read, NULL, NULL, &tm);
		printf("ready cnt:%d \n", n_ready);
		if(FD_ISSET(0, &fd_read))
		{
			memset(buf, 0, 1024);
			read(0, buf, 1024);
			printf("keyboard active!: %s\n", buf);
		}
		if(FD_ISSET(0, &fd_read))
		{
			memset(buf, 0, 1024);
			read(fd1, buf, 1024);
			printf("1.txt active!: %s\n", buf);
		}
		if(FD_ISSET(0, &fd_read))
		{
			memset(buf, 0, 1024);
			read(fd2, buf, 1024);
			printf("2.txt active!: %s\n", buf);
		}
	}
}
