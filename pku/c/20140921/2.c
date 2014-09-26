/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: Mon 22 Sep 2014 03:17:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <malloc.h>

void proc(char *str)
{
    int i, j = 0;
    char *str1 = (char *)malloc(sizeof(char) * strlen(str));
    //把小写字母先赋值到前面去
    for(i = 0; str[i] != '\0'; ++i)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str1[j] = str[i];
            j++;
        }
    }
    //把大写字母赋值到小写字母后面
    for(i = 0; str[i] != '\0'; ++i)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str1[j] = str[i];
            j++;
        }
    }
    str1[j] = '\0';
    strcpy(str, str1);
}

int main()
{
    char str[100];
    printf("enter a string:");
    scanf("%s", str);
    proc(str);
    printf("new string is %s\n", str);

    return 0;
}
