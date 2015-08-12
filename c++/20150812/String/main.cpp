/*************************************************************************
	> File Name: main.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: 2015年08月12日 星期三 19时12分13秒
 ************************************************************************/

#include<iostream>
#include"string.h"
using namespace std;

int main()
{
    String s1("hello");
    cout <<"test ctr " <<  s1 << endl;
    String s2(s1);
    cout << "test cpctr " << s1 << endl;

    return 0;
}

