/*************************************************************************
	> File Name: sort.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 10:41:59 AM EDT
 ************************************************************************/

#ifndef __SORT_H_
#define __SORT_H_

void swap(int *a, int *b);
void select_sort(int *a, int len);
void show_array(int *a, int len);
void bubble_sort(int *a, int len);
void insert_sort(int *a, int len);
void quick_sort(int *a, int len);
int partion(int *a, int len);
#endif
