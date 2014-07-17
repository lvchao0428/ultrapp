/*************************************************************************
	> File Name: vector13.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 05:06:11 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
    string s = "helloworld";

    string::size_type pos1 = s.find(string("test"), 2);

    if(pos1 != string::npos)
    {
        cout<<pos1<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }

    return 0;
}
