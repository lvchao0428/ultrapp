/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: Sun 21 Sep 2014 10:39:55 PM CST
 ************************************************************************/

#include<stdio.h>

#define M 2
#define N 2

void matrix_mul(int *m1, int *m2, int *r, int x, int y, int z)
{
    int i, j, k;
    for(i = 0; i < x; ++i)
    {
        for(j = 0; j < y; ++j)
        {
            for(k = 0; k < z; ++k)
            {
                printf("%d ", (r + i*z)[k]);
                (r + i*z)[k] += (m1 + i*y)[j]*(m2 + j*z)[k];
            }
        }
    }
}


int main()
{
    int m1[N][M], m2[M][N], r[N][N] = {0};
    int i, j;
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < M; ++j)
        {
            scanf("%d", (*(m1 + i*M) + j));
        }
    }
    for(i = 0; i < M; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            scanf("%d", (*(m2 + j*N) + j));
        }
    }
    matrix_mul(m1, m2, r, 2, 2, 2);
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            printf("%d ", *(*(r + i*N) + j));
        }
        printf("\n");
    }


    return 0;
}
