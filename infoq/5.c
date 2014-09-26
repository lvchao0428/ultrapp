/*************************************************************************
	> File Name: 5.c
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Sep 2014 02:46:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

char onceChar(char c[100])
{
    char b;
    int i, j;
    int n;
    for(i=0; c[i] != '\0'; ++i)
    {
        b = c[i];
        n = 0;
        for(j = 0; c[j] != '\0'; ++j)
        {
            if(b == c[j])
                n++;
            if(n >= 2)
                break;
        }

        if(n == 1)
            return b;
    }

}

int main()
{
    char word[100];
    scanf("%s", word);
    printf("%c\n", onceChar(word));

    return 0;
}
