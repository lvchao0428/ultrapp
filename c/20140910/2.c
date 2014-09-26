/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Sep 2014 10:00:25 AM CST
 ************************************************************************/

#include<stdio.h>

int fun(int a[])
{
    int i, j = 0;
    for(i = 7; i<100; ++i)
    {
        if((i%7==0 || i%11==0) && (i%77!=0))
        {
            a[j++] = i;
        }
    }
    return j;
}

int main()
{
    int i, j, a[100];
    int n=0;
    j = fun(a);
    for(i = 0; i<j; ++i)
    {
        printf("%d ", a[i]);
        n++;
        if(n == 5)
        {
            printf("\n");
            n = 0;
        }
    }

    return 0;
}
