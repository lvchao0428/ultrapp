#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int lcs(const string &s1, const string &s2, int m, int n)
{
    int **memo = new int*[m+1];
    int i;
    for (i = 0; i <= m; i++) 
    {
        memo[i] = new int[n+1];
    }
    int j;
    
    for(i = 0; i<=m; ++i)
    {
        for(j = 0; j<=n; ++j)
        {
            memo[i][j] = 0;
        }
    }

    for(i=1; i<=m; ++i)
    {
        for(j = 1; j<=n; ++j)
        {
            if(s1[i-1] == s2[j-1])
                memo[i][j] = memo[i-1][j-1] + 1;
            else
            {
                memo[i][j] = memo[i-1][j] > memo[i][j-1] ?
                    memo[i-1][j] : memo[i][j-1];
            }
        
        }
    }

    return memo[m][n];
}

int main(int argc, const char *argv[])
{
    string s1,s2;
    cout<<"enter:";
    cin >> s1 >> s2;
    cout<<"lcs:"<<lcs(s1, s2, s1.size(), s2.size());

    return 0;
}
