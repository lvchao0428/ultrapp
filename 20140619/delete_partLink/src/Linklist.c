/*************************************************************************
	> File Name: Linklist.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 02:24:42 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>
#include "Link.h"

void createLink(pLink *L)
{
	*L = (pLink)malloc(sizeof(Link));
	(*L)->next = NULL;
	
}

void rearInsert(pLink L)
{
	int data;
	pLink p = L;
	pLink q;
	while(p->next != NULL)
	{
		p = p->next;
	}

	while(fflush(stdin), (scanf("%d", &data))!= EOF)
	{
		q = (pLink)malloc(sizeof(Link));
		q->data = data;

		q->next = NULL;
		p->next = q;
		p = p->next;
	}
}

void outputLink(pLink L)
{
	pLink p = L->next;

	while(p!=NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void deleteNode(pLink L, int n)
{
	pLink p = L,q = L->next;

	while(q!= NULL)
	{
		if(q->data == n)
		{
			p->next = p->next->next;
		}
		p = p->next;
		q = q->next;
	}

}
