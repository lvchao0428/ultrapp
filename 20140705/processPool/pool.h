/*************************************************************************
	> File Name: pool.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 05 Jul 2014 03:28:01 AM EDT
 ************************************************************************/

#ifndef __POOL_H_
#define __POOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define S_BUSY 1
#define S_IDLE 0
typedef struct  sockaddr_in SA;

typedef struct tag
{
	pid_t s_pid ;
	int s_flag ;
	int s_read ;
	int s_write ;
	int s_cnt ;
	//参数用来衡量服务器效率
	
}CHLD, *pCHLD ;
int make_chld(pCHLD arr, int cnt);
//返回最大的s_read

#endif
