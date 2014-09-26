#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void HeapAdjust(int array[], int cur, int heapSize)
{
    int leftchild, rightchild, min_num;
    leftchild = 2*cur + 1;
    rightchild = 2*cur + 2;
    if(leftchild < heapSize && array[leftchild] > array[cur] )
        min_num = leftchild;
    else
        min_num = cur;
    if(rightchild < heapSize && array[rightchild] > array[min_num])
        min_num = rightchild;
    if(min_num != cur)
    {
        swap(&array[min_num] , &array[cur]);
        HeapAdjust(array, min_num, heapSize);
    }
    
}

void SmallHeap(int array[], int heapSize)
{
    int i;
    for(i = heapSize/2; i >= 0; i--)
    {
        HeapAdjust(array, i, heapSize);
    }
}

void input(int *a, int n)
{
    int i;
    for(i = 0; i != n; ++i)
        scanf("%d", &a[i]);
}

void print(int *a, int n)
{
    int i;
    for(i = 0; i != n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}



int main(int argc, const char *argv[])
{
    int a[100];
    int n;
    printf("enter n:");
    scanf("%d", &n);
    input(a, n);
    SmallHeap(a, n);
    print(a, n);
    return 0;
}
