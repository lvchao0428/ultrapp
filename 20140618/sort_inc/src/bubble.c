/*************************************************************************
	> File Name: bubble.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 10:48:28 AM EDT
 ************************************************************************/

#include<stdio.h>
#include "sort.h"
void bubble_sort(int *a, int len)
{
	int left=0, right=len-1, i;

	while(left < right)
	{
		for(i=left; i<right; ++i)
		{
			if(a[i] > a[i+1])
				swap(&a[i], &a[i+1]);
		}
		right--;
		for(i=right; i>left; --i)
		{
			if(a[i] < a[i-1])
				swap(&a[i], &a[i-1]);
		}
		left++;
	}
}
