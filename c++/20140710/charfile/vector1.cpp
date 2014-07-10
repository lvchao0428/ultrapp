/*************************************************************************
	> File Name: vector1.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 04:38:51 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
    vector<string> vec;
    string s;
    while(cin>>s )
    {
        vec.push_back(s);
    }   

    for(const auto &s: vec)
    {
        cout<< s <<" ";

    }
    cout<<endl;
    vector<string>::iterator it;
    
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        cout<<*it<<endl;
    }


    return 0;
}

