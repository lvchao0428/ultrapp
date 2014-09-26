/*************************************************************************
	> File Name: test_mutex.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 14 Jul 2014 07:59:30 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

#include "mutexlock.h"
using namespace std;

int main(int argc, const char *argv[])
{
    MutexLock lock;

    lock.lock();
    cout<<"lock"<<endl;
    lock.lock();
    cout<<"lock"<<endl;

    return 0;
}
