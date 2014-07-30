/*************************************************************************
	> File Name: client.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 27 Jun 2014 02:53:14 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void my_handler(int num)
{
	wait();
	exit(0);
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("USAGE: EXE PIPENAME\n");
		exit(-1);
	}
	//告诉服务器上线信息
	int fd_server = open(argv[1], O_WRONLY);
	int fd_read, fd_write;
	char buf[1024];
	int pid;
	char fifo_read_name[32] = "";
	char fifo_write_name[32] = "";

	if(fd_server == -1)
	{
		perror("open");
		exit(-1);
	}
	//确保写管道的唯一性
	sprintf(fifo_read_name, "%d_read.fifo", getpid());
	sprintf(fifo_write_name,"%d_write.fifo", getpid());
	mkfifo(fifo_read_name, 0666);
	mkfifo(fifo_write_name, 0666);

	FILE *fp = fdopen(fd_server, "w");
	//用进程号创建管道,确保唯一性
	fprintf(fp, "%d", getpid());
	fflush(fp)	;
	fd_read = open(fifo_read_name, O_RDONLY);
	fd_write = open(fifo_write_name, O_WRONLY);

	printf("id: %d, begin to talk!\n", getpid());
	if((pid = fork())> 0) //p send
	{
		signal(17, my_handler);
		close(fd_read);
		FILE * fp_write = fdopen(fd_write, "w");
		while(memset(buf,0,1024), fgets(buf, 1024,stdin) != NULL)
		{
			fprintf(fp_write, "from %d:%s", getpid(), buf);
			fflush(fp_write);
		}
		fprintf(fp_write, "bye");
		fflush(fp_write);
		kill(pid, 9);
		close(fd_write);
		unlink(fifo_read_name);
		unlink(fifo_write_name);
		while(1);
	}
	else		//c recv
	{
		close(fd_write);
		while(memset(buf, 0, 1024), read(fd_read, buf, 1024) > 0)
		{
			write(1, buf, strlen(buf));
		}


	}


}


