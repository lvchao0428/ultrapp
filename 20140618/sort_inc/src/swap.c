/*************************************************************************
	> File Name: swap.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 10:56:13 AM EDT
 ************************************************************************/

#include<stdio.h>
#include "sort.h"

void swap(int *a, int *b)
{
	int temp;
	temp  = * a;
	*a = *b;
	*b = temp;
}
