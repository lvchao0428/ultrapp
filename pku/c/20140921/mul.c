/*************************************************************************
	> File Name: mul.c
	> Author: 
	> Mail: 
	> Created Time: Sun 21 Sep 2014 11:26:09 PM CST
 ************************************************************************/

#include<stdio.h>

#define M 2
#define N 3

int print_matrix(int *a, int x, int y)
{
    int i, j;
    int sum = 0;
    for(i = 0; i < x; ++i)
    {
        for(j = 0; j < y; ++j)
        {
            printf("%d ", *(a + i*y + j));
//            sum += ()
        }
        printf("\n");
    }
}

int matrix_mul(int *a, int *b, int *c, int x, int y, int z)
{
    int i, j, k;
    for(i = 0; i<x; ++i)
    {
        for(j=0; j<y; ++j)
        {
            for(k=0; k<z; ++k)
            {
                *(c + i*z + k) += (*(a + i*y + j))*(*(b + j*z + k));
            }
        }
    }
}

void matrix_print(int *a, int x, int y)
{
    int i, j;
    for(i = 0; i<x; ++i)
    {
        for(j = 0; j<y; ++j)
        {
            printf("%d ", *(a + i*y + j));
        }
        printf("\n");
    }
}

void matrix_input(int *a, int x, int y)
{
    int i, j;
    for(i = 0; i< x; ++i)
    {
        for(j = 0; j < y; ++j)
        {
            scanf("%d", (a + i*y + j));
        }
    }
}

int main()
{
    int a[M][N], b[N][M], c[M][M] = {0};
   
    printf("enter matrix a:\n");
    matrix_input(&a[0][0], M, N);
    printf("enter matrix b:\n");
    matrix_input(&b[0][0], N, M);

    matrix_mul(&a[0][0], &b[0][0], &c[0][0], M, N, M);

    matrix_print(&a[0][0], M, N);
    matrix_print(&b[0][0], N, M);
    matrix_print(&c[0][0], M, M);

    return 0;
}
