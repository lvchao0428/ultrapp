/*************************************************************************
	> File Name: 1-5.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 03:39:17 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int n;
    double s = 0;

    scanf("%d", &n);
    
    if(n*95 >= 300)
    {
        s = 0.85 * (n*95);
    }
    else
    {
        s = n*95;
    }
    printf("%lf\n", s);

    return 0;
}
