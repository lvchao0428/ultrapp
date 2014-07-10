/*************************************************************************
	> File Name: err1.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 12:02:29 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

int main(int argc, const char *argv[])
{
    cout<<"before"<<endl;
    throw std::runtime_error("test!");

    cout<<"after"<<endl;
    
    return 0;
}
