/*************************************************************************
	> File Name: getsocketopt.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 02 Jul 2014 09:22:00 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
	int sock_fd;
	int recv_size, snd_size;
	int len_recv = sizeof(int);
	int len_snd = sizeof(int);
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	getsockopt(sock_fd, SOL_SOCKET, SO_RCVBUF,&recv_size, &len_recv);
	getsockopt(sock_fd, SOL_SOCKET, SO_SNDBUF,&snd_size, &len_snd);
	printf("send size:%d\nrecv size:%d\n", snd_size, recv_size);

	return 0;
}
