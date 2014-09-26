/*************************************************************************
	> File Name: main1.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 24 Jun 2014 07:21:44 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>

int main(int argc, char **argv)
{
	char *s = (char*)calloc(1, 1024);
	
	//puts(s);
	int i;
	for(i = 0; i<100; i++)
	{
		printf("%d\n", s[i]);
	}

	return 0;
}
