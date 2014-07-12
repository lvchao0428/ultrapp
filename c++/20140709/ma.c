/*************************************************************************
	> File Name: ma.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 09 Jul 2014 04:23:40 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#define M 5
#define N 4
int main(int argc, const char *argv[])
{
    int **a = (int **)malloc(M * sizeof(int *));

    int i, j;
    for (i = 0; i < M; i++) 
    {
        a[i] = (int *)malloc(sizeof(int) * N);
    }
    srand(time(NULL));
    for (i = 0; i < M; i++) 
    {
        for (j = 0; j < N; j++)
        {
            a[i][j] = rand()%10;
        }    
    }

     for (i = 0; i <M; i++) 
     {
         for (j = 0; j < N; j++) 
         {
             printf("%d\t", a[i][j]);
         }
         printf("\n");
         
     }
     printf("\n\n");
     for (i = 0; i < M; i++) 
     {
         free(a[i]);
     }
     free(a);
     
     
     for (i = 0; i <M; i++) 
     {
         for (j = 0; j < N; j++) 
         {
             printf("%d\t", a[i][j]);
         }
         printf("\n");
         
     }

    


    return 0;
}
