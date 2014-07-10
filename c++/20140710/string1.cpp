/*************************************************************************
	> File Name: string1.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 12:28:40 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string &shorterstring(const string &s1, 
        const string &s2)
{
    return s1.size()<s2.size() ? s1 : s2;

}


int main(int argc, const char *argv[])
{
    string s1, s2;

    cin>>s1>>s2;
    
    cout<<shorterstring(s1, s2);



    return 0;
}
