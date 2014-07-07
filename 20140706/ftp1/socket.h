#ifndef __MY_SOCKET_H__
#define __MY_SOCKET_H__
#include<stdio.h>
#include "msg.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
int listenfd_init(char* ip, char* port);
void dl_file(int fd_client);
void ul_file(int fd_client);
#endif

