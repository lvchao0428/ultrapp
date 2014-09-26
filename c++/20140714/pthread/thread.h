/*************************************************************************
	> File Name: thread.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 14 Jul 2014 07:48:37 PM CST
 ************************************************************************/

#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

class thread
{
    public:
        thread();
        ~thread();

        void start();
        static void *threadFunc(void *arg);
        void run();

        void join();
    private:
        pthread_t tid_;
        int a_;
}

#endif
