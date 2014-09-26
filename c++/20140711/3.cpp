/*************************************************************************
	> File Name: 3.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 10:56:11 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;


typedef int T;
void swap1(T &a, T &b)
{
    T temp(a);
    a = b;
    b = temp;
}

template<typename T>
void swap(T *a, T *b)
{
    T temp(*a);
    *a = *b;
    *b = temp;
}

int main(int argc, const char *argv[])
{
    int *a, *b;
    int i, j;
    cout<<"before swap, a = "<<a<<"b = "<<b<<endl;
    swap(&a, &b);
    cout<<"before swap, a = "<<a<<"b = "<<b<<endl;
    string s1, s2;
    cin>>s1>>s2;
    cout<<"s1 = "<<s1<<" s2 = "<<s2<<endl;
    swap(s1, s2);
    cout<<"s1 = "<<s1<<" s2 = "<<s2<<endl;

    return 0;
}
