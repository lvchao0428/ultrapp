/*************************************************************************
	> File Name: client.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 04 Jul 2014 07:39:19 AM EDT
 ************************************************************************/

#include "chat.h"
#include <pthread.h>
void* recv_func(void *arg);
void fill_the_obj(MSG * msg);
int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("USAGE: EXT IP port");

	}
	int fd_client ;
	fd_client = socket(AF_INET , SOCK_DGRAM, 0);

	if(fd_client == -1)
	{
		perror("socket");
		exit(-1) ;
	}
	SA server_addr ;
	bzero(&server_addr, sizeof(SA));
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	MSG msg_on, msg_chat, msg_off ;
	bzero(&msg_on, sizeof(MSG));
	msg_on.s_type = MSG_ON ;
	sendto(fd_client, &msg_on, sizeof(MSG), 0,
			(struct sockaddr*)&server_addr, sizeof(SA));
	pthread_t tid;
	int type;
	SA obj_sa;
	pthread_create(&tid, NULL, recv_func,(void*)fd_client);
	while(1)
	{

		printf("enter the chat type:\n");
		scanf("%d", &type);
		switch(type)
		{
			case 1:

				msg_chat.s_type = MSG_USR;		
				fill_the_obj(&msg_chat);	
				printf("begin send msg...\n");
				printf("ip:%s, port:%d",
						inet_ntoa(msg_chat.s_addr.sin_addr),
						ntohs(msg_chat.s_addr.sin_port));
				while(bzero(&msg_chat.s_msg, sizeof(msg_chat.s_msg)), fgets(msg_chat.s_msg, MSG_SIZE,stdin) != NULL)
				{
					msg_chat.s_len = strlen(msg_chat.s_msg) ;
					sendto(fd_client, &msg_chat, sizeof(MSG), 0, 
							(struct sockaddr*)&server_addr, sizeof(SA));

				}

				break;
			case 2:
				printf("begin grp talking...\n");
				msg_chat.s_type = MSG_GRP ;
				while(bzero(&msg_chat, sizeof(MSG)), fgets(msg_chat.s_msg, MSG_SIZE,stdin) != NULL)
				{
					msg_chat.s_len = strlen(msg_chat.s_msg) ;
					sendto(fd_client, &msg_chat, sizeof(MSG), 0, 
							(struct sockaddr*)&server_addr, sizeof(SA));
				}
				break;


		}

	}
	bzero(&msg_off, sizeof(MSG));
	msg_off.s_type = MSG_OFF ; 
	close(fd_client);


	return 0;
}

void* recv_func(void *arg)
{
	int fd_server = (int)arg;
	char buf[1024];
	while(1)
	{
		bzero(buf, 1024);
		recvfrom(fd_server, buf, 1024, 0, NULL, NULL);
		printf("recv:%s \n", buf);
	}
}

void fill_the_obj(MSG * msg)
{
	fflush(stdin);
	fflush(stdout);
	char obj_ip[1024];
	char obj_port[32];
	printf("enter the ip:");
	bzero(obj_ip, 1024);
	scanf("%s", obj_ip);
	fflush(stdin);
	printf("enter the port:");
	bzero(obj_port, 32);
	scanf("%s", obj_port);
//	printf("%s\n", obj_port);
//	printf("hello");

	(*msg).s_addr.sin_family = AF_INET;
	(*msg).s_addr.sin_addr.s_addr= inet_addr(obj_ip);
	(*msg).s_addr.sin_port = htons(atoi(obj_port));

//	printf("ip:%s\nport:%d\n", inet_ntoa((*obj).sin_addr),
//			ntohs((*obj).sin_port));
}
