/*************************************************************************
	> File Name: unique.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 07:24:59 AM EDT
 ************************************************************************/

#include<stdio.h>
#include "unique.h"


void input_elem(int *a, int n)
{
	int i;
	for(i=0; i<n; ++i)
	{
		scanf("%d", &a[i]);
	}
}

void output_elem(int *a, int n)
{
	int x = a[0], flag = 0;
	int i;

	for(i=0; i<n ; ++i)
	{
		if(flag == 0)
		{
			x = a[i];
			flag = 1;
			printf("%d ", a[i]);
		}
		if(x != a[i])
		{
			flag = 0;
		}
		
	}

}


