#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define M 5
#define N 5

typedef struct Array_
{
    int A_[M][N];
    int m_;
    int n_;
}Array;

void pointer(Array *a)
{
    int i, j;
    
    for (i = 0; i < a->m_; i++) {
        for (j = 0; j < a->n_; j++) {
            printf("%d\t", a->A_[i][j]);
        }
        printf("\n");
    }
}

void givepointer(Array *a)
{
    int i, j;
    a->m_ = M;
    a->n_ = N;
    srand(time(NULL));
    for (i = 0; i < a->m_; i++) {
        for (j = 0; j < a->n_; j++) {
            a->A_[i][j] = rand()%100;
        }
    }
}
int main(int argc, const char *argv[])
{
    
    Array a;
    givepointer(&a) ;
    pointer(&a);
    return 0;
}

