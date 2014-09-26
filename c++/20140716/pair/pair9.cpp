/*************************************************************************
	> File Name: pair9.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 17 Jul 2014 12:09:22 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


int main(int argc, const char *argv[])
{
    set<int> s;

    for(size_t ix = 0; ix != 10; ++ix)
    {
        s.insert(ix);
        s.insert(ix);
    }

    cout<<s.size()<<endl;

    s.insert(12);
    cout<<s.size()<<endl;
    s.insert(12);
    cout<<s.size()<<endl;

    return 0;
}
