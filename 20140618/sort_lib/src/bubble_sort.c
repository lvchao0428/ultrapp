/*************************************************************************
	> File Name: bubble_sort.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 02:23:44 AM EDT
 ************************************************************************/

#include<stdio.h>

#include "sort.h"
void bubble_sort(int *a, int len)
{
	int i, j,  flag= 1;

	for(i=0; i<len && flag == 1; ++i)
	{
		flag =0;
		for(j=0; j<len-i-1; ++j)
		{
			if(a[j] >= a[j+1])
			{
				swap(&a[j], &a[j+1]);
				flag = 1;
			}
		}
	}
}
