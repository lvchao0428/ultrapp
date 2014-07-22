
#include <stdio.h>
#include <string.h>
#define N 1000

int a[N];

int main(int argc, const char *argv[])
{
    int n, k;
    memset(a, 0, sizeof(a));
    scanf("%d%d", &n, &k);
    int i, j;
    for (j = 1; j <= k; j++) 
    {
        for (i = 1; i <= n; i++) 
        {
            if(i%j == 0)
            {
                a[i] = (a[i]+1)%2;
            }
        }
        
    }
    
    for (i = 1; i <= n; i++) 
    {
        if(a[i] == 1)
            printf("%d ",i);
    }
    

    return 0;
}
