/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 24 Jun 2014 10:49:10 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int index;

	for(index = 0; index < argc; index++)
	{
		printf("arg %2d: %s\n", index, argv[index]);

	}

	return 0;
}
