/*************************************************************************
	> File Name: 2-2.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 09:02:11 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    int n;
    scanf("%d", &n);
    int i=0;
    while(n != 1)
    {
        if(n%2 == 1)    
            n = 3*n+1;
        else
            n = n/2;
        i++;
    }

    printf("%d\n", i);

    return 0;
}
