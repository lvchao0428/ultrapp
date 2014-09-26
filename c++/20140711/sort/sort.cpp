/*************************************************************************
	> File Name: sort.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 08:14:26 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool cmp(int a, int b)
{
    return a>b;
}


int main(int argc, const char *argv[])
{
    int a[5] = {4, 5, 2, 6, 7};
    
    sort(a, a+5);
    int i;
    for (i = 0; i < 5; i++) 
    {
        cout<<a[i]<<' ';
    }
    cout<<endl;

    

    return 0;
}
