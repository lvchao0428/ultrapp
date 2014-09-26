/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Sep 2014 10:09:23 AM CST
 ************************************************************************/

#include<stdio.h>

void fun(int x, int pp[], int *n)
{
    int i, j = 0;
    for(i = 0; i<100; ++i)
    {
        if(i%x==0 && i%2 != 0)
        {
            pp[j++] = i;
        }
    }
    *n = j;
}

int main()
{
    int n, pp[100], x;
    while(1)
    {
        printf("enter a x:");
        scanf("%d", &x);
        fun(x, pp, &n);
        int i;
        for(i = 0; i<n; ++i)
        {
            printf("%d ", pp[i]);
        }
    }


    return 0;
}
