/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: Wed 10 Sep 2014 10:28:13 AM CST
 ************************************************************************/

#include<stdio.h>

void fun(char *tt, int pp[])
{
    int i;
    for(i = 0; tt[i] != '\0'; ++i)
    {
        pp[tt[i] - 'a'] ++;
    }
}

int main()
{
    char tt[100];
    int pp[26] = {0};

    int i;
    while(1)
    {
        scanf("%s", tt);
        fun(tt,pp);
        for(i = 0; i<26; ++i)
        {
            printf("%c %d\n", 'a' + i, pp[i]);
        }
    }
    


    return 0;
}
