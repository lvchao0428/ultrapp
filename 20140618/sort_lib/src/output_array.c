/*************************************************************************
	> File Name: output_array.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 05:54:03 AM EDT
 ************************************************************************/

#include<stdio.h>
#include "sort.h"
void output_array(char *word,int *a, int n)
{
	printf("%s", word);
	int i;
	for(i=0; i<n; ++i)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
