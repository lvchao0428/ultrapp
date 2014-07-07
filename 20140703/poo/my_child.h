/*************************************************************************
	> File Name: my_child.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 03 Jul 2014 07:27:24 AM EDT
 ************************************************************************/
#ifndef __MY_CHILD_H_
#define __MY_CHILD_H_

#include "my_socket.h"
#define S_BUSY 1
#define S_IDLE 0
typedef struct tag
{
	pid_t s_pid ;
	int s_status ;
	int s_read ;
	int s_write ;
	int s_cnt ;
}CHLD, *pCHLD
void make_chld(pCHLD arr, int cnt);
void child_main();
#endif

