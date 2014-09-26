/*************************************************************************
	> File Name: vector12.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 05:01:56 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
    string s = "helloworld";

    s.replace(4, 3, "test");

    cout<<s<<endl;

    s.replace(4, 3, string("foobar"), 3, 3);

    cout<<s<<endl;
    
    return 0;
}
