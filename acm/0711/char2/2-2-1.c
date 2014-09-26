/*************************************************************************
	> File Name: 2-2-1.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 09:37:08 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int n2, count = 0;
    
    scanf("%d", &n2);
    long long n = n2;
    while(n != 1)
    {
        if(n%2 == 1)
            n = 3*n+1;
        else
            n = n/2;
        count++;
    }

    printf("%d\n", count);

    return 0;
}
