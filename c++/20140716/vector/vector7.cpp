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
#include <algorithm>

using namespace std;



int main(int argc, const char *argv[])
{
    vector<string> vec;

    vec.push_back("beijing");
    vec.push_back("shanghai");
    vec.push_back("guangzhou");
    vec.push_back("shenzhen");
    vec.push_back("jinan");
    list<string> lst(vec.begin(), vec.end());

    for(list<string>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it << endl;    
    }

    list<string>::iterator iter1 = find(lst.begin(),
            lst.end(), "shanghai");
    lst.erase(iter1);

    list<string>::iterator first = find(lst.begin(),
            lst.end(), "guangzhou"),
        last = find(lst.begin(),lst.end(), "shenzhen");
    lst.erase(first, last);



   

    for(list<string>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it << endl;    
    }

    return 0;
}
