/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sun 22 Jun 2014 05:17:29 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>
#include "bitree.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	printf("enter a tree:\n");
	pBiTree p = (pBiTree)malloc(sizeof(BiTree));
	p = createBiTree();


	preTraverse(p);
	return 0;
}

