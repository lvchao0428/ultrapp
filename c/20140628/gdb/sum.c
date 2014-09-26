/*************************************************************************
	> File Name: sum.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 28 Jun 2014 03:29:39 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int my_sum(int n)
{
	int i, sum=0;
	for(i=1; i<=n; ++i)
	{
		sum+=i;
	}
	return sum;
}

int main()
{
	int n;
	printf("enter n:");
	scanf("%d", &n);
	printf("sum of 1to10 is:%d\n", my_sum(n));

	return 0;
}
