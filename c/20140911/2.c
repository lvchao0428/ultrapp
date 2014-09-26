/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: Thu 11 Sep 2014 09:07:53 AM CST
 ************************************************************************/

#include<stdio.h>

int *count(char *ch_p)
{
    char c;
    int i;
    int num = 0;
    for(i = 0; ch_p[i] != '\0'; ++i)
    {
        if(ch_p[i] >= 'A' && ch_p[i] <= 'Z')
        {
            ch_p[i] += 32;
        }

        if(ch_p[i] == 'a' || 
          ch_p[i] == 'e' || 
          ch_p[i] == 'i' ||
          ch_p[i] == 'o' ||
          ch_p[i] == 'u')
            num++;
    }

    return &num;
}

int main()
{
    char word[100];
    
    int num;
    gets( word );
    num = *count(word);
    printf("%s,%d",word, num);

    return 0;
}
