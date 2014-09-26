/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Sep 2014 09:33:58 AM CST
 ************************************************************************/

#include<stdio.h>

void Permusation(char *pStr, char* pBegin)
{
    if(!pStr || !pBegin)
        return ;
    if(*pBegin == '\0')
        printf("%s\n", pStr);
    else
    {
        char *pCh;
        for(pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
            Permusation(pStr, pBegin + 1);
//            printf("change twice.\n");
     //       temp = *pCh;
       //     *pCh  = *pBegin;
         //   *pBegin = temp;
            
        }
    }
}

int main()
{
    char s[100];
    printf("enter a string:\n");
    scanf("%s", s);
    Permusation(s,s);
    printf("\n%s\n", s);
    return 0;
}


