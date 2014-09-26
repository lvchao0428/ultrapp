#include <iostream>
#include <stdlib.h>

using namespace std;

int min(int a, int b, int c)
{
    return ((a > b) ? a : b) > c ? ((a> b)? a: b) : c;
}

int min_ed(const string &s1, const string &s2, int m , int n)
{
    int dis = 0, temp = 0;
    if(m!=0 && n!= 0)
    {
        if(s1[m-1] == s2[n-1])
            dis =  min_ed(s1, s2, m-1, n-1);
        else
        {
            dis =  min_ed(s1, s2, m, n-1) + 1; 
            if((temp = min_ed(s1, s2, m-1, n) + 1) < dis)
                dis = temp;
            if((temp = min_ed(s1, s2, m-1, n-1)+1) < dis)
                dis = temp;
        }
    }
    return dis;
}

int main(int argc, const char *argv[])
{
    string s1, s2;
    while(1)
    {
        cout<<"enter s1&s2:"<<endl;
        cin>>s1>>s2;
        cout<<"min edit distance is:"<<min_ed(s1, s2, s1.size(), s2.size())<<endl;
    }
    return 0;
}
