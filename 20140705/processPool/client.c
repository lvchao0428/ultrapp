/*************************************************************************
	> File Name: client.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 05 Jul 2014 08:35:35 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc ,char *argv[])
{
	if(argc != 3)
	{
		printf("USAGE:EXE IP PORT");
		exit(-1);
	}

	char buf[1024], recvbuf[1024];
	
	int fd_server;

	fd_server = socket(AF_INET, SOCK_DGRAM, 0);
	
	if(fd_server == -1)
	{
		perror("socket");
		exit(-1);
	}
	struct sockaddr_in server_addr ;
	int addrlen = sizeof(server_addr) ;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	server_addr.sin_port = htons(atoi(argv[2]));

//	if(-1 == bind(fd_server, (struct sockaddr*)&server_addr,
//				sizeof(server_addr)))
///	{
//		perror("bind");
//		exit(-1);
//	}
	
	while(fflush(stdin), fgets(buf, 1024, stdin) != NULL)
	{
		bzero(recvbuf, sizeof(recvbuf));
		sendto(fd_server,buf, sizeof(buf), 0, 
					(struct sockaddr*)&fd_server, sizeof(fd_server));
		int addrlen  = sizeof(fd_server);
		recvfrom(fd_server,recvbuf, 1024, 0, 
				(struct sockaddr*)&fd_server, &addrlen);
		printf("recv:%s\n", recvbuf);

	}


	return 0;
}
