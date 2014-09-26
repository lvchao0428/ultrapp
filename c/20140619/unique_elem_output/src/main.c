/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 07:31:04 AM EDT
 ************************************************************************/

#include<stdio.h>
#include "unique.h"

int main()
{
	int a[100];
	int i=0;

	printf("enter some integer numbers:\n");
	while(fflush(stdin), (scanf("%d", &a[i]))!= EOF)
	{	
		i++;
	}

	output_elem(a, i);
	printf("over!!!\n");

	return 0;
}



