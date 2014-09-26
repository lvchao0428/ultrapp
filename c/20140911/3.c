/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Sep 2014 09:26:39 AM CST
 ************************************************************************/

#include<stdio.h>

double s = 1;
double power(double x, int y)
{
    if(y-- > 0)
    {
        s *= x;
        power(x, y);
    }
    return s;
}

int main()
{
    double x;
    int y;
    scanf("%lf,%d", &x, &y);
    printf("%lf%f", power(x, y));

    return 0;
}

