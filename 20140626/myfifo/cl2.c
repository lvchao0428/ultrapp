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
#include <signal.h>

void handle(int num)
{
	waitpid(-1, NULL, WCONTINUED);
	exit(0);
}

int main()
{
	int fd_12w, fd_12r, 
		fd_23w, fd_23r;

	fd_12w = open("2_1.fifo", O_WRONLY);
	fd_12r = open("1_2.fifo", O_RDONLY);
	fd_23r = open("3_2.fifo", O_RDONLY);
	fd_23w = open("2_3.fifo", O_WRONLY);

	pid_t pt1, pt2;
	char buf[1024], buf1[1024];
	int read_n1, read_n2;
	if((pt1 = fork())>0)
	{
		close(fd_12r);
		close(fd_23r);
			FILE* fp = fdopen(fd_12w, "w");
			FILE* fp1 = fdopen(fd_23w, "w");
		signal(17, handle)	;
		if((pt2 = fork()) > 0)
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
			close(fd_12w);
			close(fd_23w);
		}
		else
		{	
			close(fd_12w);
			while(memset(buf, 0, 1024),
				(read(fd_12r, buf, 1024) > 0) )
			{
				write(1, buf, strlen(buf));
				if(strncmp(buf, "bye1", 3) == 0)
					break;
			}
			close(fd_12r);
		}
		fprintf(fp, "bye2");
		fprintf(fp1, "bye2");
		kill(pt1, 2);
		kill(pt2, 2);
		while(1);
	
	}
	else		//input
	{
		close(fd_23w);

		while(memset(buf, 0, 1024),
			(read(fd_23r, buf, 1024) > 0) )
		{
			write(1, buf, strlen(buf));
			if(strncmp(buf, "bye3", 3) == 0)
				break;
		}
			
		close(fd_23r);
	}
}
