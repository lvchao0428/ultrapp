
#include <stdio.h>
#include <math.h>


int main(int argc, const char *argv[])
{
    int m, n;
    double s, t;
    int i;
    while(scanf("%d%d", &m, &n),!(m==n && n ==0))
    {
        for (i = m; i <= n; i++) 
        {
            s += (1.0/(double)((int)pow(i, 2)%100000));
             
        }
        printf("%.5f\n", s);
    }



    return 0;
}
