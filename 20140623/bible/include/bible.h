/*************************************************************************
	> File Name: bible.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 23 Jun 2014 04:57:38 AM EDT
 ************************************************************************/

#ifndef __BIBLE_H_
#define __BIBLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TXT_LINE (1<<16)
//#define MAX_CHA 1024


typedef struct tagw
{
	char word[32];
	int count;
}TXT_WORD, *pTXT_WORD;
typedef struct tag
{
	int word_e_num;
	int char_num;
	int word_num;
	int line_num;
	pTXT_WORD des_word;
	char * src_txt[MAX_TXT_LINE];
	char * des_txt[MAX_TXT_LINE];
}TXT,*pTXT;

pTXT init_txt(char * file_name);
void destroy_txt(pTXT pTxt);
void trim_space(char * src);
int is_space(char ch);
int num_word_line(char *src);
int num_char_line(char *src);
void kmp_next(char * par, int *next);
void kmp_search(char * src, char *par);
int is_character(char ch);

void depunct(char *fp, char *ss);
#endif
