/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 23 Jun 2014 07:13:20 AM EDT
 ************************************************************************/

#include<stdio.h>
#include "bible.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_CHA (1<<12)


int main(int argc, char **argv)
{
	int i=0;
	pTXT pt;// = (pTXT)malloc(sizeof(TXT));

//	pt = init_txt("b.txt");
	pt = init_txt("The_Holy_Bible.txt");
//	printf("begin output.\n");
//	printf("pt->line_num:%d\n", pt->line_num);
//	printf("pt->char_num:%d\n", pt->char_num);
	
	while(i< pt->line_num)
	{
	//	printf("now :");
		puts(pt->des_txt[i]);
	//	puts(pt->src_txt[i]);
		i++;
	}
		
	return 0;
}
