
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

struct ThreadData
{
    typedef Thread::ThreadFunc ThreadFunc;
    ThreadFunc func_;

    ThreadData(ThreadFunc func)
        :func_(func)
    {}

    void runThread()
    {
        func_();
    }
};

void *threadFunc(void *arg)
{
    ThreadData *pd = static_cast<ThreadData *>(arg);
    pd->runThread();
    delete pd;
}

void Thread::start()
{
    ThreadData *data = new ThreadData(callback_);
    if(pthread_create(&tid_, NULL, threadFunc,data))
        delete data;
}

void Thread::join()
{
    pthread_join(tid_, NULL);
}
