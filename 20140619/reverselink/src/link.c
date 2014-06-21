/*************************************************************************
	> File Name: link.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 09:54:32 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>

#include "link.h"

void showLink(pLINK L)
{
	pLINK p = L->next;
	
	while(p!=NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
}
