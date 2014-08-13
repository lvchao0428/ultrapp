
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//start with 1
int lcs(char* x,char* y, int i, int j)
{
    int m = 0;
    if(i !=0 && j != 0)
    {
        if(x[i-1] == y[j-1])
            m = (lcs(x, y, i-1, j-1)+1);
        else
            m = ( (lcs(x, y, i-1, j)) > 
                (lcs(x, y, i, j-1)) ? 
                lcs(x, y, i-1, j) :
                lcs(x, y, i, j-1));
    }

    return m;
}

int main(int argc, const char *argv[])
{
   char x[100] , y[100];

   printf("enter 2 string:");
   scanf("%s %s", x, y);
   printf("%s %s\n", x, y);
   int n = lcs(x, y, strlen(x), strlen(y));
   printf("lcs:%d\n", n);
    return 0;
}
