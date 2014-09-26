/*************************************************************************
	> File Name: select_sort.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 02:28:49 AM EDT
 ************************************************************************/

#include<stdio.h>
#include "sort.h"

void select_sort(int *a, int len)
{
	int i, j, max;

	for(i=0; i<len; ++i)
	{
		max = i;
		for(j=i; j<len; ++j)
		{
			if(a[max] > a[j])
				max = j;
		}
		if(i != max)
			swap(&a[i], &a[max]);
	}
}
