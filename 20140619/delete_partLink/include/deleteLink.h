/*************************************************************************
	> File Name: deleteLink.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 11:35:48 PM EDT
 ************************************************************************/

#ifndef __DELETELINK_H_
#define __DELETELINK_H_


void createLink(pLink *L);

void headInsertLink(pLink L);

void rearInsertLink(pLink L);

void show_Link(pLink L);

pLink search(pLink L, int n);

void deleteNode(pLink L, int n);





#endif
