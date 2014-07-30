/*************************************************************************
	> File Name: hello.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 03:08:48 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{	
	char buf[100] = {"hello world"};
	printf("%s", buf);
	return 0;
}
