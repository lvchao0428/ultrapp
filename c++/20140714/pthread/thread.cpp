/*************************************************************************
	> File Name: thread.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 14 Jul 2014 07:48:24 PM CST
 ************************************************************************/

#include "thread.h"
#include <time.h>
#include <iostream>

using namespace std;

thread::thread()
    :tid_(-1)
{

}

thread::~thread()
{

}

void thread::start()
{
    pthread_create(&tid_, NULL, producer, this);
    pthread_create(&tid_, NULL, consumer, this);

}

void *thread::producer(void *arg)
{
    thread *pt = static_cast<thread *>(arg);
    pt->produce();
}

void *thread::consumer(void *arg)
{
    thread *pt = static_cast<thread *>(arg);
    pt->consume();
}


void thread::join()
{
    pthread_join(tid_, NULL);
}

