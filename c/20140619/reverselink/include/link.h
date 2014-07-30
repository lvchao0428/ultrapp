/*************************************************************************
	> File Name: link.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 09:49:06 PM EDT
 ************************************************************************/

#ifndef __LINK_H_
#define __LINK_H_

#include <stdio.h>
#include <malloc.h>

typedef struct tag
{
	int data;
	struct tag *next;
}LINK, *pLINK;
void create(pLINK *L);
void headInsert(pLINK L);
void reverse(pLINK L);
void showLink(pLINK L);

#endif
