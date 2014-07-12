/*************************************************************************
	> File Name: 2-3.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 09:55:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    double s = 0, t = 1;
    int i = 1, n = 0;

    do
    {
        t = 1/((2*i-1)*1.0);
        if(i%2 == 1)
            t = t;
        else
            t = -t;
        s += t;
        i++;
        
    }
    while( t > 0.000001);
    
    printf("%lf", s);

    return 0;
}
