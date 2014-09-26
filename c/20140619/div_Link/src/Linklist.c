/*************************************************************************
	> File Name: Linklist.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 03:00:15 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>

#include "Linklist.h"

void createLink(pLink *L)
{
	*L = (pLink)malloc(sizeof(Link));
	(*L)->next = NULL;
}

void rearInsert(pLink L)
{
	pLink p = L;
	
	while(p->next != NULL) p = p->next;
	pLink q;
	int data;
	while(fflush(stdin), (scanf("%d", &data))!= EOF)
	{
		q = (pLink)malloc(sizeof(Link));
		q->data = data;
		q->next = NULL;

		p->next = q;
		p = p->next;
	}
}

void show_Linklist(pLink L)
{
	pLink p = L->next;

	while(p!= NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
