/*************************************************************************
	> File Name: pair3.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 08:18:09 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <utility>
#include <typeinfo>
#include <stack>
using namespace std;

//void print(const map<string, int>:: value_type &p)
void print(const pair<string, int> &p)
{
    cout<<p.first<<" "<<p.second<<endl;
}

int main(int argc, const char *argv[])
{
    map<string, int> people;

    people["shenzhen"]  = 1000;
    people["beijing"] = 3000;
    people["shanghai"] = 2000;

    cout<<people["beijing"]<<endl;

    people["beijing"] = 8000;

    map<string, int>::iterator iter = people.begin();
    while(iter != people.end())
    {
        cout<<iter->first<<" "<<iter->second<<endl;
        ++iter;
    }

    cout<<"-----------"<<endl;

    for_each(people.begin(), people.end(),  print);
    
    return 0;
}
