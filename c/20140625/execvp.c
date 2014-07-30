/*************************************************************************
	> File Name: execvp.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 03:13:40 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char* buf[] = {argv[1], argv[2], NULL};
	
	execvp(buf[0],buf);
	return 0;
}
