/*************************************************************************
	> File Name: 3-3.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 10:42:16 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int s = 0, n;
    scanf("%d", &n);

    int i;
    for (i = 1; i <= n; i++) 
    {
        s+=i;
    }
    printf("%d", s);

    return 0;
}

