/*************************************************************************
	> File Name: cl3.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 26 Jun 2014 05:32:22 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
	int fd_32w, fd_32r, 
		fd_13w, fd_13r;

	fd_32w = open("3_2.fifo", O_WRONLY);
	fd_32r = open("2_3.fifo", O_RDONLY);
	fd_13w = open("3_1.fifo", O_WRONLY);
	fd_13r = open("1_3.fifo", O_RDONLY);

	pid_t fk1,fk2;
	char buf[1024], buf1[1024];
	int read_n1, read_n2;
	if(fork()>0)
	{
		close(fd_32r);
		close(fd_13r);

		FILE* fp = fdopen(fd_32w, "w");
		FILE* fp1 = fdopen(fd_13w, "w");
		while(memset(buf, 0, 1024), fgets(buf, 1024, stdin) != NULL)
		{
			if(buf[0] != '\n')
			{
				fprintf(fp, "%s\n", buf);
				fprintf(fp1, "%s\n", buf);
				fflush(fp);
				fflush(fp1);
			}
		}
		close(fd_32w);
		close(fd_13w);


	
		wait(NULL);
	}
	else		//input
	{
		close(fd_32w);
		close(fd_13w);
		
		if(fork()>0)
		{
			while(memset(buf, 0, 1024),
				(read(fd_32r, buf, 1024) > 0) )
			{
				write(1, buf, strlen(buf));
			}
			close(fd_32r);
		}
		else
		{

			while(memset(buf, 0, 1024),
				(read(fd_13r, buf, 1024) > 0) )
			{
				write(1, buf, strlen(buf));
			}
			
			close(fd_13r);
		}

		exit(0);
	}
}
