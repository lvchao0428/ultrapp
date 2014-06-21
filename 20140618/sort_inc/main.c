/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 10:59:26 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>
#include "sort.h"
#include <time.h>

int main()
{
	srand(time(NULL));
	int *a = (int *)malloc(sizeof(int));
	int i;
	for(i=0; i<10; ++i)
		a[i] = rand()%100;
	bubble_sort(a, 10);
	
	for(i=0; i<10; ++i)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
