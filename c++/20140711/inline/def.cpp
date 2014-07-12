/*************************************************************************
	> File Name: def.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 04:49:53 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stu
{
    int num;
    string name;
};
stu s = {10, "jordan"};

stu &getstu(stu &s)
{
    return s;
}

int main(int argc, const char *argv[])
{
    stu s;
    stu s1 = {11, "name"};
    getstu(s) = s1;

    cout<<s.num<<s.name<<endl;
    
    return 0;
}
