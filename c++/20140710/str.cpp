/*************************************************************************
	> File Name: str.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 09:18:52 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    string s = "hello";
    string s2 = s + " world";

    cout<< s2 <<endl;

    s += "zhangsan";

    cout<<(s < s2)<<endl;


    return 0;
}
