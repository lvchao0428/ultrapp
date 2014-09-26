/*************************************************************************
	> File Name: msg.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 05 Jul 2014 09:56:55 PM EDT
 ************************************************************************/

#ifndef __MSG_H_
#define __MSG_H_

#define MSG_SIZE 8188
#define MSG_LEN 4
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
typedef struct sockaddr_in SA;
typedef struct tag
{
	int s_len ;
	char s_buf[MSG_SIZE];
}MSG;

#endif

