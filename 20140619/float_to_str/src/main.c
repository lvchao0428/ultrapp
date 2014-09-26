/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 04:12:58 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

#include "float_to_str.h"

int main()
{
	float f;
	char s[100];
	printf("enter a float:\n");
	scanf("%f", &f);

	
	float_to_str(f, s);
	printf("float to string is: %s\n", s);

	return 0;
}
