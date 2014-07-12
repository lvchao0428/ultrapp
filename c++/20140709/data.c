/*************************************************************************
	> File Name: data.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 09 Jul 2014 08:08:42 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char *s = (char *)malloc(1000);
    int *a = (int *)malloc(1000);
    strcpy(s, "hello");
    a = (int*)s;
    printf("%s\n", (char*)a);

    return 0;
}
