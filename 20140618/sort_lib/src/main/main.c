/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 05:43:14 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <malloc.h>

#include "sort.h"

int main(int argc, char **argv)
{
	int *a  = (int *)malloc(sizeof(int));
	
	input_array(a, 10);
	output_array("origin array:", a, 10);
	
	input_array(a, 10);
	select_sort(a, 10);
	output_array("select_sort:", a, 10);

	input_array(a, 10);
	Insert_sort(a, 10);
	output_array("Insert_sort:", a, 10);

	input_array(a, 10);
	bubble_sort(a, 10);
	output_array("Insert_sort:", a, 10);

	input_array(a, 10);
	quick_sort(a, 10);	
	output_array("Insert_sort:", a, 10);


	return 0;
}

