/*************************************************************************
	> File Name: pair1.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 05:29:24 PM CST
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
    std::pair<int, string> p1;

    std::pair<int, int> p2(4, 5);
    std::pair<string, string> p3("hello", "world");

    p1.first = 1;
    
    p1.second = "test";

    cout<<p2.first<<" "<<p2.second<<endl;
    cout<<p3.first<<" "<<p3.second<<endl;
    p2 = make_pair(1, 2);
    cout<<p2.first<<" "<<p2.second<<endl;

    make_pair(string("hello"), 1);
    vector<string> v1;
    vector<list<string> > v2;
    make_pair(v1, v2);

    

}

