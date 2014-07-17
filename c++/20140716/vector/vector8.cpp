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
    
    std::string query;

    vector<string>::iterator iter = std::find(vec.begin(),
            vec.end(), "beijing");

    if(iter == vec.end())
    {
        cout<<"not found!"<<endl;
    }
    else
    {
        cout<<*iter<<endl;
    }

    return 0;
}
