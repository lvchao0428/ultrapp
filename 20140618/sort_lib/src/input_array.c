/*************************************************************************
	> File Name: input_array.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 05:50:08 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <time.h>
#include "sort.h"
void input_array(int *a, int len)
{
	int i;
	srand(time(NULL));
	for(i=0; i<len; ++i)
	{
		a[i] = rand()%100;
	}
}
