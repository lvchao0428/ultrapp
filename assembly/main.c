/*************************************************************************
	> File Name: 1.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: 2015年08月07日 星期五 16时25分25秒
 ************************************************************************/

#include<stdio.h>

int g(int x)
{
    return x + 16;
}

int f(int x)
{
    return g(x);
}

int main(void)
{
    return f(64) + 155;
}
