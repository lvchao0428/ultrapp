#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int A[5] = {1,2,3,4,5};

    int (*arr)[5] = &A;
    int i;    
    for (i = 0; i < 5; i++) {
    printf("arr:%d\n", (*arr)[i]);
    }
    return 0;
}
