/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Sep 2014 02:00:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <malloc.h>

int my_strstr(char *a, char *b)
{
    int i, j, s = 0;
    int lenb = strlen(b);
    char *c = (char*)malloc(sizeof(char)*(100));
    for(i = 0; a[i] != '\0'; ++i)
    {
        strcpy(c, a+i);
        *(c + lenb) = '\0';
        if(strcmp(c, b) == 0)
            s++;
    }

    return s;
}

int main()
{
    char A[100], B[20];
    scanf("%s %s", A, B);
    printf("%d\n", my_strstr(A, B));

    return 0;
}
