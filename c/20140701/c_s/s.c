/*************************************************************************
	> File Name: s.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 01 Jul 2014 07:46:22 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

void* my_file(void* arg);

void deal_buf(char * buf, int *pid, char * path);
int main(int argc, char *argv[])
{
	char buf[1024];
	int fd_server;
	if(argc != 2)	
	{
		printf("USAGE: EXE PIPNAME\n");
		exit(-1);
	}
	fd_server = open(argv[1], O_RDONLY);
	
	while(1)	
	{
		printf("begin:detect\n");
		
		while(memset(buf, 0, 1024), read(fd_server, buf, 1024)>0)
		{
			pthread_t tid;
			
			pthread_create(&tid, NULL, my_file, (void*)buf);
		}
	}
	
	close(fd_server);

}

void* my_file(void* arg)
{
	puts((char*)arg);
	int pid;
	char path[100];
	char fifo_path[100];
	deal_buf(arg,&pid, path );
	char  buf[1024];
	sprintf(fifo_path, "%d_write.fifo", pid);
	FILE *fp_read;
	fp_read = fopen(path, "r");
	FILE *fp_write;
	fp_write = fopen(fifo_path, "w");
	while(memset(buf, 0, 1024), fread(buf,1, 1024, fp_read) > 0)
	{
		strcpy(buf, "hello world");
		fwrite(buf, 1, 1024, fp_write);
	}
}

void deal_buf(char * buf, int *pid, char * path)
{
	int i, j;
	char num[100] = "";
	puts(buf);
	for(i = -1, j = 0; j<strlen(buf); j++)
	{
		if(buf[j] != ' ')
		{
			buf[++i] = buf[j];
		}
		else
		{
			if(i != -1 && buf[i] != ' ')
			{
				buf[++i] = ' ';
			}
		}
	}
	for(; i>=0; i--)
	{
		if(buf[i] != ' ')
			break;
	}
	buf[++i] = '\0';

	int word_pos = 0;
	sscanf(buf, "%s", path);
	word_pos = strlen(path)+1;
	sscanf(buf+word_pos, "%s", num);
	*pid = atoi(num);

}
