#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int T;

swap(int *a, int *b);
swap1(int *********a, int *********b);
int main(int argc, const char *argv[])
{
    int i = 1, j = 3;

    unsigned int ********a = &i;
   unsigned  int ********b = &j;
//    printf("pre addr: &a:%d\n", a);
  //  printf("pre addr: &b:%d\n", b);
    printf("********a:%u\n", a);
    printf("********b:%u\n", b);
    swap(&a, &b);
    printf("********a:%u\n", a);
    printf("********b:%u\n", b);
    return 0;
}

swap1(int *********a, int *********b)
{
    int ********temp = ********a;
    ********a = ********b;
    ********b = ********temp;

}

swap(int *a, int *b)
{
    int ********temp = *a;
    *a = *b;
    *b = temp;
}
