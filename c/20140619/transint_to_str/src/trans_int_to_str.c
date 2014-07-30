/*************************************************************************
	> File Name: trans_int_to_str.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 10:41:55 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "trans.h"

void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void trans(int n)
{
	char ss[100];
	int i=0, t[10];	
	while(n != 0)
	{
		ss[i] = n%10 + '0';
		n /= 10;
		i++;
	}
	ss[i] = '\0';
	char c;
	int j = 0;
	if(n > 0)
	{
		for(j=0; j<n/2; ++j)
		{
			swap(&ss[j], &ss[n-j-1]);
		}
	}
	else
	{
		ss[i] = '-';
		for(j=0; j<(n+1)/2; ++j)
		{
			swap(&ss[j], &ss[n-j]);
		}
		ss[i+1] = '\0';
	}
	printf("%s", ss);
}
