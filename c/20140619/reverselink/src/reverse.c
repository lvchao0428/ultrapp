/*************************************************************************
	> File Name: reverse.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 09:39:38 PM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
#include "link.h"

void create(pLINK *L)
{
	*L = (pLINK)malloc(sizeof(LINK));
	(*L)->next = NULL;
}

void reverse(pLINK L)
{
	pLINK p = L,q=L->next, r;
	p->next = NULL;
	while(q != NULL)
	{
		r = q;
		q = q->next;
		r->next = p->next;
		p->next = r;
	}
}
