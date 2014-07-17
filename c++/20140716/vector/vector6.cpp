/*************************************************************************
	> File Name: vector3.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 10:12:42 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;



int main(int argc, const char *argv[])
{
    vector<string> vec;

    vec.push_back("beijing");
    vec.push_back("shanghai");
    vec.push_back("guangzhou");
    vec.push_back("shenzhen");

    list<string> lst(vec.begin(), vec.end());

    for(list<string>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it << endl;    
    }

    lst.pop_back();
    lst.pop_front();

    for(list<string>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it << endl;    
    }

    return 0;
}
