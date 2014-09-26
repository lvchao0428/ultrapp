/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: Mon 22 Sep 2014 03:40:04 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int isSynmetry(char *begin, char *end)
{
    if(begin == NULL || end == NULL || begin > end)
        return 0;
    while(begin < end)
    {
        if(*begin != *end)
            return 0;
        begin ++;
        end --;
    }
    return 1;
}

int maxsymlen(char *str)
{
    char *str1, *str2;
    int maxlen = 1;
    for(str1 = str; *str1 != '\0'; ++str1)
    {
        for(str2 = str1; *str2 != '\0'; ++str2)
        {
            if(isSynmetry(str1, str2-1) == 1)
            {
                if(str2 - str1 > maxlen)
                {
                    maxlen = str2 - str1;
                }
            }
        }
    }
    
    return maxlen;
}

int main()
{

    char word[100];
    int max;
    printf("enter a string:");
    scanf("%s", word);
    max = maxsymlen(word);
    if( max == 1)
        printf("synmetry string not found.");
    else
        printf("%d\n", max);

    return 0;
}
