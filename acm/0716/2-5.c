/*************************************************************************
	> File Name: 2-5.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 01:00:01 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    double max = 0, min = 0, per, n, s = 0, i = 1;
    
    while( scanf("%lf", &n))
    {
        if(n > max)
            max = n;
        if(n < min)
            min = n;
        s+=n;
        i++;
    }

    printf("max = %.3lf\n", max);
    printf("min = %.3lf\n", min);
    printf("per = %.3lf\n", s/i);


    return 0;
}
