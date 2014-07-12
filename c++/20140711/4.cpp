/*************************************************************************
	> File Name: 4.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 11:15:48 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void swap1(T &a, T &b)
{
    T temp(a);
    a = b;
    b = temp;
}

int main(int argc, const char *argv[])
{
    int a, b;
    cin>>a>>b;

    cout<<"a = "<<a<<", b = "<<b<<endl;
    swap1(a, b);
    cout<<"a = "<<a<<", b = "<<b<<endl;


    return 0;
}
