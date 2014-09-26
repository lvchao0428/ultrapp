/*************************************************************************
	> File Name: Linklist.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 05:30:16 AM EDT
 ************************************************************************/

#ifndef __LINKLIST_H_
#define __LINKLIST_H_

typedef struct tag
{
	int data;
	struct tag *next;
}Link, *pLink;





void createList(pLink *L);
void headInsertList(pLink L);
void rearInsertList(pLink L);
void show_Linklist(pLink L);
void reverse(pLink L);


#endif
