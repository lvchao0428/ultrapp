/*************************************************************************
	> File Name: Link.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 11:41:59 PM EDT
 ************************************************************************/

#ifndef __LINK_H_
#define __LINK_H_

typedef struct tag
{
	int data;
	struct tag *next;

}Link,*pLink;
void createLink(pLink *L);

void headInsertLink(pLink L);
void rearInsert(pLink L);

void outputLink(pLink L);
pLink search(pLink L, int n);
void deleteNode(pLink L, int n);

#endif
