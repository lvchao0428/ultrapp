/*************************************************************************
	> File Name: bitree.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 21 Jun 2014 11:22:50 PM EDT
 ************************************************************************/

#ifndef __BITREE_H_
#define __BITREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree
{
	char data;
	struct BiTree *lchild,*rchild;
}BiTree, *pBiTree;

pBiTree createBiTree();

void visit(pBiTree p);

void preTraverse(pBiTree T);

#endif
