/*************************************************************************
	> File Name: Insert_sort.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 02:20:17 AM EDT
 ************************************************************************/

#include<stdio.h>
#include "sort.h"

void Insert_sort(int *a, int len)
{
	int i, j, temp;

	for(i = 1; i<len; ++i)
	{
		j = i-1;
		temp = a[i];
		while(j>=0 && temp < a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
		
	}
}
