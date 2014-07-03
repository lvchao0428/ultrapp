/*************************************************************************
  > File Name: server.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Thu 03 Jul 2014 10:02:48 AM CST
 ************************************************************************/
#include "my_socket.h"
#include <sys/select.h>
#include <sys/time.h>
int main(int argc , char* argv[])//exe ip port
{
	signal(13,SIG_IGN);
	if(argc != 3)
	{
		printf("usge : exe ip port");
		exit(-1);
	}
	fd_set read_set, ready_set ;
	int fd_server ,fd_client;
	FD_ZERO(&read_set);
	struct sockaddr_in client_addr ;
	int addrlen = sizeof(client_addr);
	fd_server = listenfd_init(argv[1],argv[2]);
	FD_SET(fd_server,&read_set);
	struct timeval tm ;
	while(1)
	{
		tm.tv_usec = 1000 ;
		tm.tv_sec = 0 ;
		ready_set = read_set ;
		select(fd_server + 1 , &ready_set, NULL, NULL, &tm);
		if(FD_ISSET(fd_server, &ready_set))
		{
			fd_client = accept(fd_server,(struct sockaddr*)&client_addr,&addrlen);
			handle_request(fd_client);
		}	
	}

}
