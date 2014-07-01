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

void handle(int num)
{
	waitpid(-1, NULL, WCONTINUED);
	exit(0);
}

int main()
{
	int fd_32w, fd_32r, 
		fd_13w, fd_13r;

	fd_32w = open("3_2.fifo", O_WRONLY);
	fd_32r = open("2_3.fifo", O_RDONLY);
	fd_13w = open("3_1.fifo", O_WRONLY);
	fd_13r = open("1_3.fifo", O_RDONLY);

	pid_t pt1,pt2;
	char buf[1024], buf1[1024];
	int read_n1, read_n2;
	if((pt1 = fork())>0)
	{
		close(fd_32r);
		close(fd_13r);
		signal(17, handle);
		FILE* fp = fdopen(fd_32w, "w");
		FILE* fp1 = fdopen(fd_13w, "w");
		if((pt2 = fork())>0)
		{
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
		}
		else
		{
			close(fd_32w);
			while(memset(buf, 0, 1024),
				(read(fd_32r, buf, 1024) > 0) )
			{
				write(1, buf, strlen(buf));
				if(strncmp(buf, "bye2", 3) == 0)
					break;

			}
			close(fd_32r);
		}

		fprintf(fp, "bye3");
		fprintf(fp1, "bye3");
	
	}
	else		//input
	{
		close(fd_13w);
		

		while(memset(buf, 0, 1024),
			(read(fd_13r, buf, 1024) > 0) )
		{
			write(1, buf, strlen(buf));
			if(strncmp(buf, "bye1", 3) == 0)
				break;
		}
		
		close(fd_13r);

	}
}
