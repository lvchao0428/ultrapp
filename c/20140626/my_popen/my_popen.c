/*************************************************************************
	> File Name: my_popen.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 09:24:35 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int read_n;
	char buf[1024];
	fp = popen("ls -l","r");

	read_n = fread(buf, 1, 1024, fp);

	printf("read_n: %d \n", read_n);
	
	
	printf("read from popen :\n%s\n", buf);

	return 0;
}
