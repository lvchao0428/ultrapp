/*************************************************************************
	> File Name: static.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 12:56:28 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    double pi = 3.1415;
    int val = static_cast<int>(pi);

    cout<<val<<endl;
    void *p = new int[8];
    int *ptr = static_cast<int*>(p);
    cout<<*ptr<<endl;
    char *pc = reinterpret_cast<char*>(ptr);

    return 0;
}
