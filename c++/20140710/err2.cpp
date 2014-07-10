/*************************************************************************
	> File Name: err2.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 12:06:54 AM CST
 ************************************************************************/

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
    try
    {
        int num;
        cin>> num;
        if(num == 1)
            throw out_of_range("test1");
        if(num == 2)
            throw out_of_range("test2");

        cout<<num<<endl;
    }
    catch(...)
    {
        cout<<"catch a exception"<<endl;
    }


    return 0;
}
