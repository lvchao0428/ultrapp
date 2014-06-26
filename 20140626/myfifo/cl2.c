/*************************************************************************
	> File Name: cl2.c
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
	int fd_12w, fd_12r, 
		fd_23w, fd_23r;

	fd_12w = open("2_1.fifo", O_WRONLY);
	fd_12r = open("1_2.fifo", O_RDONLY);
	fd_23r = open("3_2.fifo", O_RDONLY);
	fd_23w = open("2_3.fifo", O_WRONLY);

	pid_t fk1,fk2;
	char buf[1024], buf1[1024];
	int read_n1, read_n2;
	if(fork()>0)
	{
		close(fd_12r);
		close(fd_23r);

		FILE* fp = fdopen(fd_12w, "w");
		FILE* fp1 = fdopen(fd_23w, "w");
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
		close(fd_12w);
		close(fd_23w);


	
		wait(NULL);
	}
	else		//input
	{
		close(fd_12w);
		close(fd_23w);
		
		if(fork()>0)
		{
			while(memset(buf, 0, 1024),
				(read(fd_12r, buf, 1024) > 0) )
			{
				write(1, buf, strlen(buf));
			}
			close(fd_12r);
		}
		else
		{

			while(memset(buf, 0, 1024),
				(read(fd_23r, buf, 1024) > 0) )
			{
				write(1, buf, strlen(buf));
			}
			
			close(fd_23r);
		}

		exit(0);
	}
}
