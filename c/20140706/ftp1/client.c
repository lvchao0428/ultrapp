/*************************************************************************
	> File Name: my_client.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 02 Jul 2014 10:37:48 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "msg.h"
void recv_msg(int fd_client);
void download_file(int fd_client);
void trim_space(char *buf);
void send_command(int fd_client, char *comd);
void upload_file(int fd_client);
void recv_dir(int fd_client);

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("usage:exe server ip server_port!\n ");
		exit(-1);

	}

	int fd_client;
	struct sockaddr_in server_addr;
	if((fd_client = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		exit(-1);
	}
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port  = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	if(-1 == connect(fd_client, (struct sockaddr*)&server_addr, sizeof(server_addr)))
	{
		perror("connect");
		close(fd_client);
		exit(-1);
	}
	char comd[1024];
	while(1)
	{

		send_command(fd_client, comd);
		if(strncmp(comd, "ls", 2) == 0)
		{
			
			recv_msg(fd_client); 
		}
		else if(strncmp(comd, "download", 8) == 0)
		{
			download_file(fd_client);
		}
		else if(strncmp(comd, "cd", 2) == 0)
		{
			recv_dir(fd_client);
		}
		else if(strncmp(comd, "upload", 6) == 0)
		{
			upload_file(fd_client);
		}
		else if(strncmp(comd, "rm", 2) == 0)
		{
			
		}
	}
	close(fd_client);

	return 0;
}

void recv_dir(int fd_client)
{
	MSG msg;
	bzero(&msg, sizeof(msg));
	char buf[1024];
	bzero(buf, 1024);
	recv(fd_client, &msg, MSG_LEN, 0);
	recv(fd_client, &msg, msg.s_len + MSG_LEN, 0);

	printf("path:%s\n", msg.s_buf);
}

void recv_msg(int fd_client)
{
	printf("ready to recv msg...\n");
	MSG msg;
	//recv dir
	do
	{
		bzero(&msg, sizeof(MSG));
		recv(fd_client, &msg, 4, 0);
		recv(fd_client,	msg.s_buf, msg.s_len, 0);
		
		printf("%s\n", msg.s_buf);

	}while(msg.s_len != 0);

}

void download_file(int fd_client)
{
	MSG msg , rcv_msg;
	int fd_file;
	memset(&msg, 0, sizeof(msg));
	printf("input filename:");
	scanf("%s", msg.s_buf);
	fd_file = open(msg.s_buf, O_WRONLY | O_CREAT, 0666);
	msg.s_len = strlen(msg.s_buf);
	send(fd_client, &msg, msg.s_len + MSG_LEN, 0);

	while(1)
	{
		memset(&rcv_msg, 0, sizeof(MSG));
		recv(fd_client, &rcv_msg, MSG_LEN, 0);
		if(rcv_msg.s_len > 0)
		{
			recv(fd_client, rcv_msg.s_buf, rcv_msg.s_len, 0);
			write(fd_file, rcv_msg.s_buf, rcv_msg.s_len);
		}
		else 
			break;
		
	}
	close(fd_file);
	
}
void upload_file(int fd_client)
{
	MSG msg ;
	int fd_file;
	int read_n;
	bzero(&msg, sizeof(msg));
	printf("input upload name:");
	fflush(stdin);
	scanf("%s", msg.s_buf);
	fd_file = open(msg.s_buf, O_RDONLY);
	if(fd_file == -1)
	{
		perror("cannot open the upload file.");
	}
	msg.s_len = strlen(msg.s_buf);
	send(fd_client, &msg, msg.s_len + MSG_LEN, 0);

	while(bzero(&msg, sizeof(msg)), (read_n = read(fd_file, msg.s_buf,MSG_SIZE)) > 0)
	{
		msg.s_len = read_n;
		send(fd_client, &msg, msg.s_len + MSG_LEN, 0);
	}
	msg.s_len = 0;
	send(fd_client, &msg, msg.s_len + MSG_LEN, 0);
	close(fd_file);

}

void send_command(int fd_client, char* comd)
{
	bzero(comd, 1024);
	printf("enter the command:");
	fgets(comd, 1024, stdin);
	trim_space(comd);
	MSG snd_msg;
	
	//send msg
	bzero(&snd_msg, sizeof(snd_msg));
	strcpy(snd_msg.s_buf, comd)	;
	snd_msg.s_len = strlen(snd_msg.s_buf);

	send(fd_client, &snd_msg, snd_msg.s_len + MSG_LEN, 0);

}

void trim_space(char *buf)
{
	int i, j;
	for(i=0, j=0; buf[j] != '\0'; ++j)
	{
		if(buf[j] != ' ')
		{
			buf[i++] = buf[j];
		}
		else
		{
			if(buf[i-1] != ' ')
			{
				buf[i++] = ' ';
			}
		}
		
	}
	for(; buf[i] == ' '; --i);
	buf[++i] = '\0';
}
