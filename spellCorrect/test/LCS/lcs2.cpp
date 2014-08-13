
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
//start with 1
int memo[100][100];
using namespace std;
int lcs(const string &a,const string &b, int i, int j)
{
    if(i ==0 || j == 0)
        return 0;
    if(memo[i][j] != -1)
        return memo[i][j];
    
    if(a[i-1] == b[i-1])
    {
        memo[i][j] = lcs(a, b, i-1, j-1)+1;
    }
    else
    {
        int t1 = lcs(a, b, i-1, j);
        int t2 =  lcs(a, b, i, j-1);
        memo[i][j] = t1 > t2 ? t1 : t2;
        return memo[i][j];
    }

}

int main(int argc, const char *argv[])
{
    string s1 = argv[1];
    string s2 = argv[2];

    memset(memo, -1, sizeof memo);
    cout<<lcs(s1,s2,s1.size(), s2.size())<<endl;

    return 0;

}
