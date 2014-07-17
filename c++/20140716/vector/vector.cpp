/*************************************************************************
	> File Name: vector.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 09:54:16 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(int argc, const char *argv[])
{
    vector<string> vec;
    vec.push_back("hello ");
    vec.push_back("world");

    vector<string> vec2(vec);

    vector<string> vec3(vec.begin(), vec.end());

    vector<string> vec4(10, "test");

    list<string> lst(vec.begin(), vec.end());

    
    for(list<string>::iterator it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it <<endl;
    }

    return 0;
}
