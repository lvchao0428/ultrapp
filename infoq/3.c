/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Sep 2014 02:13:03 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

//使用桶排序思维

void fillbucket(int n, int a[6])
{
    random();
    int i;
    while(n-- > 0)
    {
        i = rand()%6;
        a[i] ++;
    }
}

void print_rate(int n, int a[6])
{
    int i;
    for(i = 0; i<6; ++i)
    {
        printf("point %d : %lf\n", i+1, (double)a[i]/(double)n);
    }
}


int main()
{
    int a[6] = {0};
    int n;
    scanf("%d", &n);
    fillbucket(n , a);
    print_rate(n, a);
    return 0;
}

