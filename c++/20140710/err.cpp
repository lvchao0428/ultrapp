/*************************************************************************
	> File Name: err.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 09:59:24 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main(int argc, const char *argv[])
{
    try
    {
        int num;
        cin >> num;
        if(num == 1)
        {
            throw exception("test1");
        }
        if(num == 2)
        {
            throw exception("test2");
        }
        cout<<num <<endl;
    }
    catch(...)
    {
        cout<<"catch a exception"<<endl;
    }

    return 0;
}
