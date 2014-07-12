/*************************************************************************
	> File Name: arrmalloc.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 09 Jul 2014 05:17:26 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int *a = (int *)malloc(sizeof(int) * 5);
    int i;
    for (i = 0; i < 5; i++) 
    {
        a[i] = i;
    }
    for (i = 0; i < 5; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);

    for (i = 0; i < 5; i++) 
    {
        printf("%d ", a[i]);
    }
    


    
    


    return 0;
}
