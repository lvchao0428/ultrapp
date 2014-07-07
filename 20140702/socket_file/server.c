/*************************************************************************
	> File Name: server.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 02 Jul 2014 03:53:54 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//tcp


#define IP "192.168.1.68"
#define PORT 9999
int main()
{
	int fd_server;
	int fd_client;
	fd_server = socket(AF_INET, SOCK_STREAM, 0);

	if(fd_server == -1)
	{
		perror("socket");
		exit(-1);
	}
	struct sockaddr_in server_addr;
	memset(&server_addr,0,sizeof(server_addr));
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr(IP);
	if(bind(fd_server, (const struct sockaddr*)&server_addr, 
				sizeof(server_addr)) == -1)
	{
		perror("bind");
		close(fd_server);
		exit(-1);
	}

	if(listen(fd_server, 5)==-1)
	{
		perror("listen");
		close(fd_server);
		exit(-1);
	}

	struct sockaddr_in client_addr ;
	int len = sizeof(client_addr) ;
	fd_client = accept(fd_server,
			(struct sockaddr*)&client_addr, &len);
	char filename[128] = "";
	char fruits[1024];
	int recv_n, send_n;
	while(memset(filename, 0, 128),(recv_n = recv(fd_client, filename, 128,0)) > 0 )
	{
//	printf("recv from IP: %s:%d\nMsg:%s\nLen:%d\n", 
//			inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port) 
//			,recv_buf, recv_n);
	printf("filename:");
		puts(filename);
		if(recv_n > 0)
		{
			printf("filename recved...sending\n");
		}
		printf("begin reading\n");
		FILE* fp = fopen(filename, "r");
		if(fp == NULL)
		{
			perror("file");
			exit(-1);
		}
		while(memset(fruits, 0, 1024), fgets(fruits, 1024, fp) != NULL)
		{
			send_n = send(fd_client, fruits, strlen(fruits), 0);
		//	printf("send to IP: %s:%d\nMsg:%s\nLen:%d\n", 
		//	inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port),
		//	recv_buf, send_n);
		}
	}
	return 0;
}
