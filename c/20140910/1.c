/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2014年09月10日 星期三 08时45分02秒
 ************************************************************************/

#include<stdio.h>

int fun(int a[], int below[], int m)
{
    int avg = 0;
    int sum = 0;
    int n = 0;
    int i, j;
    for(i = 0; i<m; ++i)
    {
        sum += a[i];
    }
    
    avg = sum / m;
    j = 0;
    for(i = 0; i<m; ++i)
    {
        if(a[i] <= avg)
        {
            n++;
            below[j++] = a[i];
        }
    }
    
    return n;
}

int main()
{
    printf("enter 5 numbers:\n");
    int i,  a[5], b[5], j;
    for(i = 0; i<5; ++i)
    {
        scanf("%d", &a[i]);
    }
    printf("%d students' score below the avg.\n", j = fun(a, b, 5));
    for(i = 0; i<j; ++i)
    {
        printf("lowest %dth is %d\n", i, b[i]);
    }


    return 0;
}
