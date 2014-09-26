/*************************************************************************
	> File Name: define.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 03:17:23 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


#define SWAP(a, b) {\
    int temp(a);\
    a = b;\
    b = temp;\
}

int main(int argc, const char *argv[])
{
    int a, b;
    cin>>a>>b;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    SWAP(a, b);
    cout<<"a = "<<a<<", b = "<<b<<endl;


    return 0;
}
 
