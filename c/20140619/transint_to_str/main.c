/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 10:46:26 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "trans.h"
int main()
{
	int i;

	printf("enter a int:");
	scanf("%d", &i);
	trans(i);

	return 0;
}
