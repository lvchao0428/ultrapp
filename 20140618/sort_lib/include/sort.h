/*************************************************************************
	> File Name: sort.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 02:26:28 AM EDT
 ************************************************************************/
#ifndef _SORT_H_
#define _SORT_H_


#include <stdio.h>

void input_array(int *a, int len);
void swap(int *a, int *b);
void bubble_sort(int *a, int len);
void Insert_sort(int *a, int len);
void quick_sort(int *a, int len);
void select_sort(int *a, int len);
void output_array(char *word,int *a, int len);

#endif
