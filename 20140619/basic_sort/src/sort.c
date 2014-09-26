/*************************************************************************
	> File Name: sort.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 10:32:56 AM EDT
 ************************************************************************/

#include<stdio.h>
#include "sort.h"

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void select_sort(int *a ,int len)
{
	int i, j=0, min;

	for(i=0; i<len; ++i)
	{
		min = i;
		for(j=i; j<len; ++j)
		{
			if(a[min] > a[j])
				min = j;
		}
		if(min != i)
			swap(&a[min],&a[i]);
	}
}

void show_array(int *a, int n)
{
	int i;
	for(i=0; i<n; ++i)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

void bubble_sort(int *a, int len)
{
	int low =0,high = len-1, i;

	while(low < high)
	{
		for(i=low; i<high; ++i)
		{
			if(a[i] > a[i+1])
			{
				swap(&a[i], &a[i+1]);
			}
		}
		high--;
		for(i=high; i>low; --i)
		{
			if(a[i] < a[i-1])
			{
				swap(&a[i], &a[i-1]);
			}
		}
		low++;
	}
}

void insert_sort(int *a, int len)
{
	int i, j, temp;
	
	for(i=1; i<len; ++i)
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

int partion(int *a, int len)
{
	int pivot, low, high, key;

	low = 0;
	high = len-1;
	key = a[low];
	while(low < high)
	{
		while(low<high && key < a[high])
			high--;
		if(low < high)
			swap(&a[low], &a[high]);
		while(low<high && key > a[low]) 
			low++;
		if(low < high)
			swap(&a[low], &a[high]);
	}
	a[low] = key;
	return low;
}


void quick_sort(int *a, int len)
{
	int pivot;

	if(len>0)
	{
		pivot = partion(a, len);
		quick_sort(a, pivot);
		quick_sort(&a[pivot+1], len-(pivot+1));
	}
}
