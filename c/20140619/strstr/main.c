/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 11:10:22 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "strstr.h"


int main()
{
	char s1[100], s2[100];
	char *c;
	printf("enter 2 string:");
	scanf("%s%s", s1, s2);
    c =	my_strstr(s1, s2);
	printf("find: %s", c);

	return 0;
}

