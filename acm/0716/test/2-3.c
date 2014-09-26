/*************************************************************************
	> File Name: 2-3.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 01:39:44 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int n, t, i= 0, j;

    scanf("%d", &n);

    while(n >= 0)
    {
        j = i;
        t = 2*n+1;
        i++;
        n--;
        while(j > 0)
        {
            printf(" ");
            j--;
        }
        while(t > 0)
        {
            printf("#");
            t--;
        }
        printf("\n");
    }


    return 0;
}
