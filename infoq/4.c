/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: Wed 24 Sep 2014 02:24:26 PM CST
 ************************************************************************/

#include<stdio.h>

int min_int(int N)
{
    int i = 0, t = 0, s = 0;

    while(1)
    {
        i++;
        s = N*i;
        t = 1;
        while(s > 0)
        {
            t = s%10;
            //t保存其中一位整数，不为1 则不符合 
            if(t != 1 && t != 0)
                break;
            s /= 10;
        }
        
        if(t == 0 || t == 1)
            return i;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    printf("%d\n", min_int(N));

    return 0;
}
