/*************************************************************************
	> File Name: client.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 02 Jul 2014 04:40:02 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>



#define IP "192.168.1.68"


#define PORT 9999
void trim_n(char *s);

int main(int argc, char *argv[])
{
	int fd_client, fd_server;
	fd_client = socket(AF_INET, SOCK_STREAM, 0);

	if(fd_client == -1)
	{
		perror("socket");
		exit(-1);
	}
	struct sockaddr_in client_addr, server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = inet_addr(IP);
	fd_server = connect(fd_client, (const struct sockaddr*)&server_addr,
				sizeof(struct sockaddr));
	if(fd_server == -1)
	{
		perror("connet");
		close(fd_client);
		exit(-1);
		
	}
	//client socket	
	char filename[128];
	while((memset(filename, 0, 128),(printf("enter the filename:")),
	 (fgets(filename, 128, stdin)!= NULL )))
	{
	
	char recv_buf[1024] = "";
		trim_n(filename);
	
	//send
		int send_n = send(fd_client, filename,strlen(filename) , 0);
		puts(filename);
		if(send_n > 0)
		{
			printf("send success~\n");
		}
	int recv_n;
	//recv
		while(memset(recv_buf, 0, 1024), (recv_n = 
			recv(fd_client, recv_buf, 1024, 0))>0)
	{
	//	printf("recv from ip:%s\nMsg:%s\nLen:%d\n",
	//			inet_ntoa(server_addr.sin_addr), recv_buf, recv_n);
		puts(recv_buf);
	}
	}	
		return 0;

}

void trim_n(char *s)
{
	int i=0;
	while(s[i] != '\n')
		i++;

	s[i] = '\0';
}
