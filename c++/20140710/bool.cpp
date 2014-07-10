/*************************************************************************
	> File Name: bool.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 10:06:27 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    bool res;
    string s1 = "hello";
    string s2 = "world";

    res = (s1 < s2);
    
    cout << res;
    return 0;
}
