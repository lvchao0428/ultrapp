/*************************************************************************
	> File Name: client.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sun 06 Jul 2014 03:26:44 AM EDT
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
#include <errno.h>
#include <dirent.h>

#include "msg.h"

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("USAGE :EXE server IP PORT");
		exit(-1);
	}
	int fd_client, fd_file, size_num = 0;
	MSG rcv_msg, msg ;
	SA server_addr ;
	if((fd_client = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		exit(-1);
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);

	if(-1 == connect(fd_client, (struct sockaddr*)&server_addr, 
				sizeof(server_addr)))
	{
		perror("connect ");
		close(fd_client);
		exit(-1);
	}
	printf("recv direction...\n");
	MSG dirmsg;	
	do
	{
		bzero(&dirmsg, sizeof(dirmsg));
		//接受单个目录长度
		recv(fd_client, &dirmsg, 4, 0);
		//接受单个目录信息
		recv(fd_client, dirmsg.s_buf, dirmsg.s_len, 0);

		
		printf("length:%d %s\n",dirmsg.s_len, dirmsg.s_buf);
	}while(dirmsg.s_len != 0);
		
	//download
	printf("input the filename:");
	bzero(&msg, sizeof(msg));
	scanf("%s", msg.s_buf);
	fd_file = open(msg.s_buf, O_WRONLY | O_CREAT, 0666);
	if(fd_file == -1)
	{
		perror("file write");
		exit(-1);
	}
	msg.s_len = strlen(msg.s_buf);
	send(fd_client, &msg, msg.s_len + MSG_LEN, 0);
	printf("send filename over : %s\n", msg.s_buf);
	char bbuff[1024];
	int buflen;
	while(1)
	{
		memset(&rcv_msg, 0, sizeof(MSG));
		recv(fd_client, &rcv_msg, MSG_LEN, 0);
		
		printf("msglen:%d\n", rcv_msg.s_len);
		if(rcv_msg.s_len > 0)
		{
			recv(fd_client, rcv_msg.s_buf, rcv_msg.s_len, 0);
			printf("msg:%s\n", rcv_msg.s_buf);
			write(fd_file, "how are you", rcv_msg.s_len);
		}
		else
			break;
	}
	printf("rend file over...\n")	;
	close(fd_file);
	close(fd_client);
	return 0;
}


