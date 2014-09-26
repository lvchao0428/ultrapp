/*************************************************************************
	> File Name: 2-1.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 01:24:07 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trifunc(int n)
{
    return n*n*n;
}

int main(int argc, const char *argv[])
{
    int i, j, k, s = 0;

    for(i = 1; i<10; ++i)
    {
        for(j = 0; j<10; ++j)
        {
        
            for(k = 0; k<10; ++k)
            {
                s = i*100 + j*10+ k;
                if(s == (trifunc(i) + trifunc(j)+ trifunc(k)))
                {
                    printf("%d\n", s);
                }
            }
        }
    }


    return 0;
}
