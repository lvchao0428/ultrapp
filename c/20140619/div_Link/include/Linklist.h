/*************************************************************************
	> File Name: Linklist.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 04:40:01 AM EDT
 ************************************************************************/

#ifndef __LINKLIST_H_
#define __LINKLIST_H_

typedef struct tag
{
	int data;
	struct tag *next;
}Link, *pLink;

void createLink(pLink *L);
void rearInsert(pLink L);
void show_Linklist(pLink L);


#endif
