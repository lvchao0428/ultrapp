/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Sep 2014 08:11:21 AM CST
 ************************************************************************/

#include<stdio.h>

int main()
{
    int a, b, c, d;
    char e;
    scanf("(%d+%di)%c(%d+%di)", &a, &b,&e, &c, &d);
    if(e == '+')
        printf("(%d+%di)%c(%d+%di)=%d+%di", a, b,e, c, d,a+c, b+d);
    else if(e == '-')
        printf("(%d+%di)%c(%d+%di)=%d+%di", a, b,e, c, d,a-c, b-d);
    return 0;
}
