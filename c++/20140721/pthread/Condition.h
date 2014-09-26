/*************************************************************************
	> File Name: cond.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 14 Jul 2014 09:14:06 PM CST
 ************************************************************************/

#ifndef COND_H_
#define COND_H_

#include <pthread.h>
#include <stdexcept>

class MutexLock;

class Condition
{
    public:
        Condition(MutexLock &lock);
        ~Condition();

        void wait();
        void notify();
        void notifyAll();

    private:
        pthread_cond_t cond_;
        MutexLock &lock_;
};

#endif
