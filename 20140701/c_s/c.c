/*************************************************************************
	> File Name: c.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 01 Jul 2014 08:59:12 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("USAGE: EXE PIPNAME\n");
		exit(-1);
	}

	FILE* fd_server = fopen(argv[1], "w");
	FILE* fd_read;
	
	char buf[1024];
	char fifo_read_name[32] = "";
	sprintf(fifo_read_name, "%d_read.fifo", 10);
	mkfifo(fifo_read_name, 0666);
	printf("read to begin recv:\n");
	while(1)
	{
		memset(buf, 0, 1024);
		printf("gets pid&name:\n");
		fgets(buf, 100, stdin);
		
		printf("buf:%s\n", buf);
		fscanf(fd_server, "%s", buf);
	fd_read = fopen(fifo_read_name, "r");
		printf("fifo_read_name:", fifo_read_name);
		while(memset(buf, 0, 1024), fread(buf, 1, 1024, fd_read) > 0)
		{
			
			printf("%s", buf);
		}
	}
}
