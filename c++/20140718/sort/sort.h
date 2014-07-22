
#ifndef SORT_H_
#define SORT_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *a, int n);
void show(int *a, int n);
void select_sort(int *a, int n);
void insert_sort(int *a, int n);
int partion(int *a, int n);
void quick_sort(int *a, int n);


#endif  /*SORT_H_*/
