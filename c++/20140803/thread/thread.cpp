
#include "thread.h"

Thread::Thread(ThreadFunc func)
    :callback_(func),
    tid_(0),
    is_Started_(false)
{}

Thread::~Thread()
{
    if(is_Started_)
    {
        pthread_detach(tid_);
    }
}

void Thread::start()
{
    is_Started_ = true;
    pthread_create(&tid_, NULL, callback_, NULL);
}

void Thread::join()
{
    pthread_join(tid_, NULL);
    is_Started_ = false;
}
