/*************************************************************************
	> File Name: 1-6.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 03:42:02 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if( ((a + b) > c) && ((a - b) < c))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}
