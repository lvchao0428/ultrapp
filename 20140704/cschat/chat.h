/*************************************************************************
	> File Name: chat.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 04 Jul 2014 04:40:27 AM EDT
 ************************************************************************/

#ifndef __CHAT_H_
#define __CHAT_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define MSG_USR 1
#define MSG_GRP 2
#define MSG_ON  3
#define MSG_OFF 4
#define MSG_SIZE 1024 

typedef struct sockaddr_in SA ;
#define MSG_LEN (8192 - MSG_SIZE)

typedef struct tagmsg
{
	int s_type ;
	int s_len ;
	SA s_addr ;
	char s_msg[MSG_SIZE] ;
}MSG;
typedef struct tagusr
{
	SA s_addr ;
	struct tagusr* s_next ;
}USR, *pUSR;

#endif
