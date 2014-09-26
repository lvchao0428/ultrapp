/*************************************************************************
	> File Name: test1.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 28 Jun 2014 04:01:45 AM EDT
 ************************************************************************/

#include<stdio.h>

int main()
{
	printf("core dump\n");
	*(char *)0 = 0;

	return 0;
}
