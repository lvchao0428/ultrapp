/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 04:34:31 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "Linklist.h"
void divid_Link(pLink L1, pLink L2, pLink L3);

int main(int argc, char ** argv)
{
	pLink L1, L2, L3;
	createLink(&L1);
	createLink(&L2);
	createLink(&L3);
	printf("enter L1:");
	rearInsert(L1);
	show_Linklist(L1);
	printf("answer is:");
	divid_Link(L1,L2,L3);
	printf("L2:\n");
	show_Linklist(L2);
	printf("L3:\n");
	show_Linklist(L3);
	printf("over.!\n");

	return 0;
}

void divid_Link(pLink L1, pLink L2, pLink L3)
{
	int i=0;
	pLink p = L1->next, q = L2,r = L3, t;
	while(p!=NULL && q!=NULL)
	{
		i++;
		if(i%2==0)
		{
			t = p;
			p = p->next;
			t->next = q->next;
			q->next = t;

		}
		else
		{
			t = p;
			p = p->next;
			t->next = r->next;
			r->next = t;
		}
	}
}
