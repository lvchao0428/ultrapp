/*************************************************************************
	> File Name: vector11.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 04:44:17 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
    string s = "helloworld";

    cout<<s.substr(5, 3)<<endl;

    s.append("hello");

    cout<<s<<endl;

    s.append("hello", 3);

    cout<<s<<endl;

    s.append(string("world"));
    cout<<s<<endl;

    s.append(8,'s');
    cout<<s<<endl;

    string tmp = "zhangsan";

    string::iterator it1 = find(tmp.begin(), tmp.end(), 'h'),
        it2 = find(tmp.begin(), tmp.end(), 'g');
    s.append(it1, it2);
    
    cout<<s<<endl;

    return 0;
}

