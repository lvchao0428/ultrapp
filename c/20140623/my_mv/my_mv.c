/*************************************************************************
	> File Name: my_mv.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 23 Jun 2014 02:37:09 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int fd_wr, fd_rd, read_n;
	char buf[1024];

	if(argc != 3)
	{
		printf("three few args!\n");
	}
	fd_rd = open(argv[1], O_RDONLY);
	fd_wr = open(argv[2], O_WRONLY | O_CREAT, 0777);
	if(fd_rd == -1 || fd_wr == -1)
	{
		perror("fail:");
		exit(-1);
	}
	while(memset(buf,0,1024), (read_n = read(fd_rd, buf, 1024))>0)
	{
		write(fd_wr, buf, read_n);
	}

	return 0;
}
