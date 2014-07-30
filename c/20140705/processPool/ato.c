/*************************************************************************
	> File Name: ato.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 05 Jul 2014 09:15:41 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <string.h>

int main()
{
	char buf[1024];
	printf("enter buf:\n");
	fgets(buf, 1024, stdin);
	printf("%d", atoi(buf));

	return 0;
}
