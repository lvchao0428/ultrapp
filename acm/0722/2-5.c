
#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a, b, c;

    while( scanf("%d%d%d", &a, &b, &c), 
            !(a==b&&b==c&&c==0))
    {
        printf("%.*lf",c, a*1.0/b);
    }

    return 0;
}
