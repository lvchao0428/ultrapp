/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 10:35:50 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "sort.h"

int main(int argc, char **argv)
{
	int a[10], n=10, i;
//	printf("please enter the n:\n");
//	scanf("%d", &n);
//	a = (int *)malloc(sizeof(int)*n);
	
	printf("please enter %d integer numbers:\n", n);
	for(i=0; i<n; ++i)
	{
		scanf("%d", &a[i]);
	}
			
	//select_sort(a, n);
//	bubble_sort(a, n);
//	printf("bubble_sort answer are:\n");
//	show_array(a, n);
	
//	insert_sort(a, n);
//	printf("insert_sort answer are:\n");
//	show_array(a, n);
	
	quick_sort(a, n);
	printf("quick_sort answer are:\n");
	show_array(a, n);

	return 0;
}

