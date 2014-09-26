/*************************************************************************
	> File Name: 5.c
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Sep 2014 10:48:18 AM CST
 ************************************************************************/

#include<stdio.h>

int IsPrime(int n)
{
    int i;
    for(i = 2; i<n; ++i)
    {
        if(n%i == 0）
        {
            break;
        }
    }
    if(i >= n)
    {
        return 0;
    }
    return 1;
}

void fun(int m, int k, int xx[])
{
    int i, j = 0;
    for(i = m; i<m + k; )
    {
        if(IsPrime(i) == 1)
        {
            xx[j++] = i;
            printf("%d ", i);
            i++;
        }
    }
}

int main()
{
    int m, k, xx[100], i;
    while(1)
    {
        printf("enter m,k,xx[]\n");
        scanf("%d %d", &m, &k);
        fun(m, k, xx);

    }
    return 0;
}
