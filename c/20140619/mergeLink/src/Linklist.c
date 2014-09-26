/*************************************************************************
	> File Name: Linklist.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 05:05:58 AM EDT
 ************************************************************************/

#include<stdio.h>
#include "Linklist.h"


void createList(pLink *L)
{
	*L = (pLink)malloc(sizeof(Link));
	(*L)->next = NULL;
}

void headInsertList(pLink L)
{//尾插
	pLink p = L, q;	
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

void rearInsertList(pLink L)
{//头插
	pLink p = L, q;
	int data;
	while(fflush(stdin), (scanf("%d", &data))!= EOF)
	{
		q = (pLink)malloc(sizeof(Link));
		q->data = data;
		q->next = p->next;
		p->next = q;
		
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
	printf("\n");
}

void reverse(pLink L)
{
	pLink p = L, q= L->next, r;
	p->next = NULL;
	while(q!=NULL)
	{
		r = q;
		q = q->next;
		r->next = p->next;
		p->next = r;
	}


}
