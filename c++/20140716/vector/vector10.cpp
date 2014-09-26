/*************************************************************************
	> File Name: vector10.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 11:02:38 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> vec;
    cout<<"size:"<<vec.size()<<"capacity:"<<vec.capacity()
        <<endl;

    vec.reserve(10);
    for(vector<int>::size_type ix = 0;
            ix != 24; ++ix)
    {
        vec.push_back(0);
    }
    cout<<"size:"<<vec.size()<<"capacity:"<<vec.capacity()
        <<endl;

    vec.reserve(30);
    cout<<"size:"<<vec.size()<<"capacity:"<<vec.capacity()
        <<endl;

    while(vec.size() != vec.capacity())
    {
        vec.push_back(0);
    }

    cout<<"size:"<<vec.size()<<"capacity:"<<vec.capacity()
        <<endl;


    vec.push_back(42);

    cout<<"size:"<<vec.size()<<"capacity:"<<vec.capacity()
        <<endl;


    

    return 0;
}

