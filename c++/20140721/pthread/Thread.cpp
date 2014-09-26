/*************************************************************************
	> File Name: Thread.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 15 Jul 2014 03:21:09 PM CST
 ************************************************************************/

#include "Thread.h"
#include "Buffer.h"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

Thread::Thread(Buffer &buffer):
    tid_(0),buffer_(buffer)
{
    srand(time(NULL));
}

void Thread::start()
{
    pthread_create(&tid_, NULL, threadFunc, this);
}

void *Thread::threadFunc(void *arg)
{
    Thread *pt = static_cast<Thread *>(arg);
    pt->run();

    return NULL;
}

void Thread::run()
{
    cout<<"run"<<endl;
}

void Thread::join()
{
    pthread_join(tid_, NULL);
}
