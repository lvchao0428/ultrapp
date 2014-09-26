/*************************************************************************
	> File Name: vector9.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 10:52:17 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
    list<string> lst(10);
    cout<<lst.size()<<endl;

    cout<<lst.empty()<<endl;

    lst.resize(100);

    cout<<lst.size()<<endl;

    return 0;
}


