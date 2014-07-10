/*************************************************************************
	> File Name: string2.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 12:33:41 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

char &get_val(string &str, string::size_type ix)
{
    return str[ix];
}

int main(int argc, const char *argv[])
{
    string s = "hello";
    get_val(s, 2) = 's';

    cout<<s <<endl;

    return 0;
}
