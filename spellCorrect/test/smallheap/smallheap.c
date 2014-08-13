#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void HeapAdjust(int a[], int low, int high)
{
    int i, temp;

    temp = a[low];
    for(i = 2*low; i <= high; i*=2)
    {
        if(i < high && a[i] < a[i+1])
            i++;
        if(temp >= a[i])
            break;
        else
        {
            a[low] = a[i];
            low = i;
        }
    }
    a[low] = temp;
}

void HeapSort(int a[], int n)
{
    int i, temp;
    
    for(i = n/2; i >= 1; --i)
    {
        temp = a[1];
        a[1] = a[i+1];
        a[i=1] = temp;
        HeapAdjust(a, 1, i);
    }
}

void print(int a[], int n)
{
    int i;
    for(i = 1; i<= n; ++i)
    {
        printf("%d " , a[i]);
    }
    printf("\n");
}

void input(int a[], int n)
{
    int i;
    for(i = 1; i<= n; ++i)
        scanf("%d", &a[i]);
}

int main(int argc, const char *argv[])
{
    int a[100];
    int n;
    printf("enter the n:");
    scanf("%d", &n);
    input(a, n);
    HeapSort(a, n);
    print(a, n);

    return 0;
}
