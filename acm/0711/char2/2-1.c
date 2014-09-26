/*************************************************************************
	> File Name: 2-1.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 08:09:52 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, const char *argv[])
{
    int i, j;
    int n, m;
    for(i=1; i<=9; ++i)
    {
        for(j=0; j<=9; ++j)
        {
            n = 1100*i + 11*j;
            m = floor(sqrt(n) + 0.5);
            if( n == (m*m))
                printf("%d\n", n);
        }
    }


    return 0;
}
