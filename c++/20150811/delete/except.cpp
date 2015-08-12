/*************************************************************************
	> File Name: except.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: 2015年08月11日 星期二 23时10分54秒
 ************************************************************************/

#include<iostream>
#include<stdexcept>

using namespace std;

int main()
{
    cout << "before" << endl;
    throw std::runtime_error("test!");
    cout << "after" << endl;

    return 0;
}

