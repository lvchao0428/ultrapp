/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 02:44:15 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>
#include "Link.h"


void del_partLink(pLink L1, pLink L2);

int main()
{
	pLink L1,L2;
	createLink(&L1);
	createLink(&L2);

	printf("enter L1:");
	rearInsert(L1);
	outputLink(L1);

	printf("enter L2:");
	rearInsert(L2);
	outputLink(L2);
	
	printf("after delete:");
	del_partLink(L1, L2);
	outputLink(L1);
	
	return 0;
}


void del_partLink(pLink L1, pLink L2)
{
	pLink p = L1, q = L2->next;

	
		while(q!=NULL)
		{
			deleteNode(p, q->data);
			q = q->next;
		}
		
	
}

