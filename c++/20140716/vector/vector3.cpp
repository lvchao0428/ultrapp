/*************************************************************************
	> File Name: vector3.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 10:12:42 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main(int argc, const char *argv[])
{
    vector<string> vec;

    vec.push_back("beijing");
    vec.push_back("shanghai");
    vec.push_back("guangzhou");
    vec.push_back("shenzhen");

    for(vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << endl;    
    }

    for(vector<string>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
    {
        cout << *it << endl;    
    }
    
    return 0;
}
