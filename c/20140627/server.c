/*************************************************************************
	> File Name: server.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 27 Jun 2014 03:28:16 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define NUM 512
//连接信息
typedef struct tag
{
	int s_read ;
	int s_write ;
}CLIENT_NODE;

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("UASGE: EXE PIPENAME \n");
		exit(-1);
	}
	char fifo_write_name[128];
	char fifo_read_name[128];
	int fd_server;
	int client_pid;
	int fd_read,fd_write;
	char buf[1024];
	CLIENT_NODE client_info[NUM];	//
	memset(client_info, -1, sizeof(client_info));
	fd_server = open(argv[1], O_RDONLY);	//只读方式打开监听文件
	fd_set read_set, ready_set;				
	FD_ZERO(&read_set);			
	FD_SET(fd_server,&read_set);//将server加入read_set集合
	struct timeval tm;
	while(1)
	{
		tm.tv_sec = 0;
		tm.tv_usec = 1000;
		ready_set = read_set;
		select(1024, &ready_set, NULL, NULL, &tm);

		if(FD_ISSET(fd_server, &ready_set))
		{
			memset(buf, 0, 1024);
			if(read(fd_server, buf, 1024) == 0)
				continue;
			client_pid = atoi(buf);

			printf("client %d on !\n", client_pid);
			sprintf(fifo_write_name, "%d_read.fifo", client_pid);
			sprintf(fifo_read_name, "%d_write.fifo", client_pid);
			
			fd_write = open(fifo_write_name, O_WRONLY);
			fd_read = open(fifo_read_name, O_RDONLY);

			int index;
			for(index = 0; index < NUM; index++)
			{
				if(client_info[index].s_read == -1)
					break;
			}

			if(index < NUM)
			{
				client_info[index].s_read = fd_read;
				client_info[index].s_write = fd_write;
			}
			else
			{
				kill(client_pid, 9);
				close(fd_read);
				close(fd_write);
				unlink(fifo_write_name);
				unlink(fifo_read_name);
			}
			//
			FD_SET(fd_read, &read_set);
		}
		int index;
		for(index = 0; index < NUM ; ++index)
		{
			if(FD_ISSET(client_info[index].s_read, &ready_set))
			{
				char recvbuf[1024] = "";
				read(client_info[index].s_read, recvbuf, 1024);
				if(strncmp(recvbuf, "bye", 3) == 0)
				{
					printf("a client off\n");
					close(client_info[index].s_read);
					close(client_info[index].s_write);
					FD_CLR(client_info[index].s_read, &read_set);
					memset(client_info + index, -1, sizeof(CLIENT_NODE));
				}
				else
				{
					int send_index;
					for(send_index = 0; send_index < NUM; send_index++)
					{
						if(client_info[send_index].s_write != -1)
						{
							write(client_info[send_index].s_write, recvbuf, strlen(recvbuf));
						}
					}
				}
			}
		}
			
		
	}

}





