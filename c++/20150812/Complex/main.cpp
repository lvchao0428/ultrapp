/*************************************************************************
	> File Name: main.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: 2015年08月12日 星期三 20时11分12秒
 ************************************************************************/

#include<iostream>
#include"complex.h"
using namespace std;

int main()
{
    mycomplex c1(1, 2);
    mycomplex c2(2, 3);
    mycomplex c3 = c1 + c2;

    cout << c1 << c2 << c3<<endl;

    return 0;
}
