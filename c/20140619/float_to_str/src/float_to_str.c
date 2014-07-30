/*************************************************************************
	> File Name: float_to_str.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 07:51:02 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>
#include "float_to_str.h"

void float_to_str(float f, char *s)
{
	float f1, f2;
	//f1存储整数部分，f2存储小数部分
	int i1, i2;	
	i1 = f;
	f2 = (f-i1*1.0);
	i2 = f2*1000000;
	int j=0;

	while(i2 != 0)
	{
		s[j++] = i2%10 + '0';
		i2 /= 10;
	}
	s[j++] = '.';
	while(i1 != 0)
	{
		s[j++] = i1%10 + '0';
		i1 /=10;
	}
	s[j] = '\0';

	int i;
	char c;
	for(i=0; i<j/2; ++i)
	{
		c = s[i];
		s[i] = s[j-i-1];
		s[j-i-1] = c;
	}

}

