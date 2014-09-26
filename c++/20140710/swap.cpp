/*************************************************************************
	> File Name: swap.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 10:25:14 AM CST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

void swap(int &a, int &b)
{
    int temp(a);
    a = b;
    b = temp;
}

void swap1(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, const char *argv[])
{
    int a(1), b(2);
//    cin>>a>>b;
    cout<<"a = "<<a <<" b = "<<b<<endl;;
    cout<< "after the exchange\n";
    swap1(a, b);

    cout<<"a = "<<a <<" b = "<<b<<endl;;
    return 0;
}
