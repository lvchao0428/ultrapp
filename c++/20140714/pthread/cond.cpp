/*************************************************************************
	> File Name: cond.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 15 Jul 2014 09:40:55 AM CST
 ************************************************************************/

#iclude "cond.h"
#include <stdexcept>

Condition::Condition(MutexLock &lock)
    :lock_(lock)
{
    if(pthread_cond_init)
}
