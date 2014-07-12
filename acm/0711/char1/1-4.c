/*************************************************************************
	> File Name: 1-4.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 10:45:04 AM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main(int argc, char *argv[])
{
//    scanf("%d", &n);
    double d, s;
    scanf("%lf", &d);
    s = sin(d*PI/180);
    printf("sin(%lf) = %lf\n", d,s );
//    printf("cos(%f) = %f\n", d,cos(d));
        
    

    return 0;
}
