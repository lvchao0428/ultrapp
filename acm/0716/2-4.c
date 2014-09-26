/*************************************************************************
	> File Name: 2-4.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 12:55:11 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int n, s = 0, t =1, i, j;

    scanf("%d", &n);

    for(i=1; i<=n; ++i)
    {
        t = 1;
        for(j = 1; j<=i; ++j)
        {
            t *= j;
        }

        s += t;
    }

    printf("%d\n", s%1000000);



    return 0;
}
