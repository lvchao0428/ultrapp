/*************************************************************************
	> File Name: 1-1.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 10:35:47 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    float a, b, c, avg = 0;

    scanf("%f%f%f", &a, &b, &c);
    avg = (a + b + c)/3;
    printf("%.3f\n",avg);
    return 0;
}
