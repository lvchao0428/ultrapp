/*************************************************************************
	> File Name: my_open.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sun 22 Jun 2014 09:42:33 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fd_wr, read_n;
	char buf[1024];
	if(argc != 2)
	{
		printf("two few args !\n");
	}
	fd_wr = open(argv[1], O_WRONLY);
	if(fd_wr == -1)
	{
		perror("fail:");
		exit(-1);
	}
	printf("fd: %d \n", fd_wr);
	while(memset(buf,0,1024),read_n = read(fd_wr, buf, 1024))
	{	
		
		printf("read_n:%d\n", read_n);
		write(fd_wr,buf,read_n);

	}
	close(fd_wr);

}
