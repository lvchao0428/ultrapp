/*************************************************************************
	> File Name: fork_chat_v1.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 26 Jun 2014 02:56:25 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char buf[1024];
	int fds[2];
	int fds2[2];
	pipe(fds);
	pipe(fds2);
	if(fork() > 0)//recv
	{
		close(fds[1]);
		close(fds2[0]);		//父进程关闭读

		
		while(memset(buf, 0, 1024), read(fds[0],buf, 1024)>0)
		{
			printf("parent read:\n");
			write(1, buf, strlen(buf));
		}
		close(fds[0]);
		printf("father begin write:\n");
	//	waitpid(-1, NULL, 0);		//等待子进程关闭读
		FILE *fp1 = fdopen(fds2[1], "w");
		if(fp1 == NULL)
			printf("fdopen\n");
		while(memset(buf, 0, 1024), fgets(buf, 1024, stdin)!= NULL)
		{
			fprintf(fp1, "from parent: %s\n", buf);
			fflush(fp1);
		}

		close(fds2[1]);				//父进程关闭写
		wait(NULL);
		printf("after wait");
	}
	else
	{
		close(fds[0]);
		close(fds2[1]);//子进程关闭写
//		sleep(2);   //父进程关闭读
	//	printf("child fd[0]:%d, child fd[1]:%d\n", fds[0], fds[1]);
		FILE* fp = fdopen(fds[1], "w");
		if(fp == NULL)
			printf("fdopen\n");
		while(memset(buf, 0, 1024), fgets(buf, 1024, stdin) != NULL)
		{
			if(buf[0] != '\n')
			{
			fprintf(fp, "from child: %s", buf);
			fflush(fp);
			}
		}
		close(fds[1]);
		printf("chind write over:");
		
		while(memset(buf, 0, 1024), read(fds2[0],buf, 1024)>0)
		{
			write(1, buf, strlen(buf));
		}
		printf("after child read.\n");
		close(fds2[0]);//子进程关闭读
		exit(0);
	}

