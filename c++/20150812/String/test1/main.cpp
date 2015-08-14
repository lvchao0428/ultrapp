/*************************************************************************
	> File Name: main.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: 2015年08月12日 星期三 19时37分52秒
 ************************************************************************/

#include<iostream>
#include"String.h"
using namespace std;


int main()
{
    String s1("hello");
    String s2;
    s2 = s1;
    String s3(s1);

    cout << s1 << " " << s2 << " " << s3 << endl;

    return 0;
}
