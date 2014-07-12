/*************************************************************************
	> File Name: 1-7.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 04:09:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isLeapyear(int n)
{
    if( (((n%4 == 0)&& (n%100 != 0))) || (n%400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, const char *argv[])
{
    int n;
    scanf("%d", &n);

    if(isLeapyear(n))
        printf("%d is a leapyear\n", n);
    else
        printf("%d is not a leapyear\n", n);

    
    return 0;
}
