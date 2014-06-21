/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 05:11:07 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>
#include "Linklist.h"

void merge_Link(pLink L1, pLink L2, pLink L3);
int main(int argc, char **argv)
{
	pLink L1, L2, L3;	

	createList(&L1);
	createList(&L2);
	createList(&L3);
	printf("headInsert L1:\n");
	headInsertList(L1);
	show_Linklist(L1);
	printf("rearInsert L2:\n");
	rearInsertList(L2);
	show_Linklist(L2);
	printf("merge answer:\n");
	merge_Link(L1, L2, L3);
	show_Linklist(L3);

	return 0;
}


void merge_Link(pLink L1, pLink L2, pLink L3)
{
	reverse(L2);

	pLink p = L1->next,q = L2->next,r = L3, t;

	while(p!=NULL && q!= NULL)
	{
		if(p->data > q->data)
		{
			t = q;
			q = q->next;
			t->next = NULL;
			r->next = t;
			r=r->next;
		}
		else
		{
			t = p;
			p = p->next;
			t->next = NULL;
			r->next = t;
			r = r->next;
		}

	}
	if(p!=NULL)
	{
		r->next = p;
	}
	if(q!=NULL)
		r->next = q;

}
