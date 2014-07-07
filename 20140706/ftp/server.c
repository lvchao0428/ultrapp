/*************************************************************************
	> File Name: server.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 05 Jul 2014 10:00:29 PM EDT
 ************************************************************************/
#include "my_socket.h"
#include <signal.h>
#include <errno.h>
#include <dirent.h>

void send_dir(int fd_client);
void sig_handle(int num)
{
	while(waitpid(-1, NULL, WNOHANG) > 0) ;
}

int main(int argc, char * argv[])
{
	signal(13, SIG_IGN);
	signal(17, sig_handle);

	if(argc != 3)
	{
		printf("USAGE: EXE IP PORT");
		exit(-1);
	}
	
	int fd_server, fd_client ;
	struct sockaddr_in client_addr ;
	int addrlen = sizeof(client_addr);
	fd_server = listenfd_init(argv[1], argv[2]);

	
	while((fd_client = accept(fd_server, 
					(struct sockaddr*)&client_addr, &addrlen)) > 0)
	{
		if(fd_client == -1)
		{
			if(errno == EINTR)
			{
				continue ;

			}
		}
		printf("a client connet :%s :%d\n",
				inet_ntoa(client_addr.sin_addr),
				ntohs(client_addr.sin_port));

		
		if(fork() == 0)
		{
			close(fd_server);
		//	send_dir(fd_client);
			printf("begin handle...download...\n");
			handle_request(fd_client);
			exit(0);
		}
	}
}

void send_dir(int fd_client)
{
	DIR *pDir;
	struct dirent* myent;

	pDir = opendir(".");

	int mylenth = 0 ;

	char buf[1024];
	MSG msg;
	while((myent = readdir(pDir)) != NULL)
	{
		
		bzero(&msg, sizeof(msg));

		sprintf(msg.s_buf, "%s %d", 
				myent->d_name, myent->d_reclen)	;

		msg.s_len = strlen(msg.s_buf);
		printf("length: %d\n", msg.s_len);
		send(fd_client, &msg, msg.s_len + MSG_LEN, 0);
		
	} 

	bzero(&msg, sizeof(msg));
	send(fd_client, &msg, 8188 + 4, 0);


	
}

