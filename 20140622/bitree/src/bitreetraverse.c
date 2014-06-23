/*************************************************************************
	> File Name: bitreetraverse.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 21 Jun 2014 11:22:26 PM EDT
 ************************************************************************/

#include<stdio.h>
#include "bitree.h"
#include <malloc.h>

#define MAX_STACK 50

pBiTree createBiTree()
{
	char c;
	pBiTree p;
	fflush(stdin);
	scanf("%c", &c);
	if(c == '#')
		return NULL;
	else
	{
		p = (pBiTree)malloc(sizeof(BiTree));
		p->data = c;

		p->lchild = createBiTree();
		p->rchild = createBiTree();
		return p;
	}
}

void visit(pBiTree p)
{
	printf("%c ", p->data);
}

void preTraverse(pBiTree T)
{
	pBiTree stack[MAX_STACK], p = T;
	int top = -1;

	while(p!= NULL || top != -1)
	{
		while(p!= NULL)
		{
			visit(p);
			stack[++top] = p;
			p = p->lchild;
		}
		p = stack[top--];
		p = p->rchild;
	}
}
