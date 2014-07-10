/*************************************************************************
	> File Name: c.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 04:46:40 PM CST
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    char s[100];

    while(memset(s, 0, 100), scanf("%s", s) != EOF)
    {
        printf("%s\n", s);
    }

    return 0;
}
