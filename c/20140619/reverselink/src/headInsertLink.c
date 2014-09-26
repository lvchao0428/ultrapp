/*************************************************************************
	> File Name: headInsertLink.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 09:48:12 PM EDT
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "link.h"
void headInsert(pLINK L)
{
	int data;
	pLINK p = L;
	while(fflush(stdin), scanf("%d", &data) != EOF)
	{
		pLINK q = (pLINK)malloc(sizeof(LINK));
		q->data = data;
		q->next = p->next;
		p->next = q;
	}
}
