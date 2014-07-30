/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 09:53:37 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>
#include "link.h"

int main()
{
	pLINK L = (pLINK)malloc(sizeof(LINK));
	L->next = NULL;
	create(&L);
	showLink(L);
	headInsert(L);
	showLink(L);
	return 0;
}
