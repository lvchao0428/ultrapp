#include <iostream>
#include <string>

using namespace std;

int min(int a, int b)
{
    return a < b ? a : b;
}

int min_ed(const string &s1, const string &s2, int m , int n)
{
    int max1 = s1.size();
    int max2 = s2.size();

    int **arr = new int*[max1 + 1];
    int i, j;
    for(i = 0; i< max1 + 1; ++i)
        arr[i] = new int[max2 + 1];

    for(i = 0; i < max1 + 1; ++i)
        arr[i][0] = i;
    for(i = 0; i < max2 + 1; ++i)
        arr[0][i] = i;
    for(i = 1; i < max1 + 1; ++i)
    {
        for(j = 1; j < max2 + 1; ++j)
        {
            int d;
            int temp = min(arr[i-1][j] + 1,
                    arr[i][j-1] + 1);
            if(s1[i-1] == s2[j-1])
                d = 0;
            else
                d = 1;
            arr[i][j] = min(temp, arr[i-1][j-1] + d);
        }
    }

    int dis = arr[max1][max2];

    for(i = 0; i < max1 + 1; ++i)
    {
        delete [] arr[i];
        arr[i] = NULL;
    }
    delete [] arr;
    arr = NULL;

    return dis;
}    

int main(int argc, const char *argv[])
{
    string s1, s2;

    while(1)
    {
        cout<<"enter 2 string:"<<endl;
        cin>>s1>>s2;
        cout<<"min edit distance word is:"<<
            min_ed(s1, s2,s1.size(), s2.size())<<endl;
    }

    
    return 0;
}


