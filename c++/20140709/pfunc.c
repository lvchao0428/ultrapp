/*************************************************************************
	> File Name: pfunc.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 09 Jul 2014 06:52:23 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*func)(int,int);

void print(int a, int b)
{
    printf("test1\n");
}

void print2(int a, int b)
{
    printf("test2\n");
}

int main(int argc, const char *argv[])
{
    func f1 = &print;
    f1(0, 0);
    f1 = &print2;
    f1(0,0);


    return 0;
}
