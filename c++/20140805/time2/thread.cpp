#include "thread.h"

Thread::Thread()
    :tid_(0),
    is_Started_(false)
{

}

Thread::Thread(const ThreadFunc &callback)
    :tid_(0),
    is_Started_(false),
    callback_(callback)
{

}

Thread::~Thread()
{
    if(is_Started_)
        pthread_detach(tid_);
}

void Thread::setCallback(const ThreadFunc &cb)
{
    callback_ = cb;
}

void *Thread::threadFunc(void *arg)
{
    Thread *pt = static_cast<Thread *>(arg);
    pt->callback_();

    return NULL;
}

void Thread::start()
{
    pthread_create(&tid_, NULL, threadFunc, this);
}

void Thread::join()
{
    pthread_join(tid_, NULL);
}

