/*************************************************************************
	> File Name: quick_sort.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 02:11:25 AM EDT
 ************************************************************************/

#include<stdio.h>
#include "sort.h"

int partion(int *a, int len)
{
	int pivot, low, high, key;
	key  = a[0];
	low = 0;
	high = len -1;
	while(low < high)
	{
		while(low < high && key <= a[high]) high--;
		if(low < high)
			swap(&a[low], &a[high]);
		while(low < high && key > a[low]) low++;
		if(low < high)
		{
			swap(&a[low], &a[high]);
		}
	}
	

	return low;
}

void quick_sort(int *a , int len)
{
	int pivot;

	if(len >0)
	{
		pivot = partion(a, len);
		quick_sort(a,pivot);

		quick_sort(&a[pivot + 1], len-(pivot + 1));

	}
}
