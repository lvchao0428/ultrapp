/*************************************************************************
	> File Name: my_socket.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 05 Jul 2014 10:27:38 PM EDT
 ************************************************************************/

#ifndef __MY_SOCKET_H_
#define __MY_SOCKET_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include "msg.h"
int listenfd_init(char *ip, char *port);
void handle_request(int fd_client);



#endif
