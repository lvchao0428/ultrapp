
#include <stdio.h>

int main(int argc, const char *argv[])
{
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i <= n; i++) 
    {
        if(i %2 == 0)
        printf("%d\n", i);
    }
    
    return 0;
}
