/*************************************************************************
	> File Name: def1.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 05:05:30 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string add( const string &s1, const string &s2)
{
    return s1;
}

int add(int a,int b)
{
    return a + b;
}

int main(int argc, const char *argv[])
{
    cout<<add("hello", "world")<<endl;

    cout<<add( 1, 2)<<endl;

    return 0;
}
