/*************************************************************************
	> File Name: test_main.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 15 Jul 2014 03:37:47 PM CST
 ************************************************************************/

#include "Factory.h"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{

    Factory fac(5, 2, 1);
    fac.start();

    return 0;
}
