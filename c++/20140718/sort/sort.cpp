

#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *a, int n)
{
    int left = 0, right  = n-1;
    int i, j;
    
    while( left < right)
    {
        for(i = left; i< right; ++i)
        {
              if(a[i] > a[i+1]) 
                swap(&a[i], &a[i+1]);
        }
        right--;
        for(j = right; j>left; --j)
        {
            if(a[j] < a[j-1])
                swap(&a[j], &a[j-1]);
        }
        left ++;
    }
}
void show(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++) 
    {
        printf("%d ", a[i]);
    }
}



void select_sort(int *a, int n)
{
    int i, j, min, temp;

    for (i = 0; i < n; i++) 
    {
        temp = a[i];
        min = i;
        for (j = i; j < n; j++) 
        {
            if(a[j] < temp)
            {
                temp = a[j];
                min = j;
            }
        }
        if(min != i)
            swap(&a[i], &a[min]);
    }
    
}
void insert_sort(int *a, int n)
{
    int i, j, temp;

    for(i = 1; i<n; ++i)
    {
        j = i-1;
        temp = a[i];
        while( j >= 0 && temp < a[j])
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = temp;
        
    }
}

int partion(int *a, int n)
{
    int first = 0, second = -1, key = a[n-1];

    while(first != n)
    {
        if(a[first] < key)
        {
            swap(&a[first], &a[second + 1]);
            second ++;
        }
        else
        {
            first ++;
            continue;
        }
    }

    swap(&a[first-1], &a[second + 1]);

    return second + 1;
}

void quick_sort(int *a, int n)
{
    int pivot;
    if(n >= 0)
    {
        pivot = partion(a, n);
        quick_sort(a, pivot);
        quick_sort(&a[pivot+1], n-(pivot + 1));
    }
}
