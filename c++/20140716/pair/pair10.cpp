/*************************************************************************
	> File Name: pair10.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 17 Jul 2014 12:15:36 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void print(const string &s)
{
    cout<<s<<" ";
}

int main(int argc, const char *argv[])
{
    set<string> s;

    s.insert("hello");
    s.insert("world");
    s.insert("test");
    s.insert("foo");
    s.insert("bar");

    for_each(s.begin(), s.end(), print);
    cout<<endl;

    s.erase("test");
    for_each(s.begin(), s.end(), print);
    cout<<endl;

    set<string>::iterator iter = s.find("bar");

    if(iter == s.end())
    {
        cout<<"404"<<endl;
    }
    else
    {
        s.erase(iter);
    }

    for_each(s.begin(), s.end(), print);
    cout<<endl;


    return 0;
}
