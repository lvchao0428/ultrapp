
#include "threadpool.h"
#include "thread.h"

using namespace std;

Threadpool::Threadpool(size_t queueSize, size_t poolSize)
    :empty_(mutex_),
    full_(mutex_),
    queueSize_(queueSize),
    poolSize_(poolSize),
    is_started_(false)
{}

Threadpool::~Threadpool()
{
    if(is_started_)
        stop();
}

void Threadpool::addTask(const Task &task)
{
    MutexLockGuard lock(mutex_);
    while(queue_.size() >= queueSize_)
        empty_.wait();

    queue_.push(task);
    full_.notify();
}

Threadpool::Task Threadpool::getTask()
{
    MutexLockGuard lock(mutex_);
    while(queue_.empty() && is_started_)
        full_.wait();

    Task task;
    if(!queue_.empty())
    {
        task = queue_.front();
        queue_.pop();
        empty_.notify();
    }

    return task;
}

void Threadpool::runInThread()
{
    while(is_started_)
    {
        Task task(getTask());
        if(task)
        {
            task();
        }
    }
}

void Threadpool::start()
{
    if(is_started_)
        return;

    is_started_ = true;

    for(size_t i = 0; i!=poolSize_; ++i)
    {
        threads_.push_back(
                new Thread(bind(&Threadpool::runInThread,this
                        )));
    }

    for(size_t i = 0; i!= poolSize_; ++i)
    {
        threads_[i]->start();
    }
}

void Threadpool::stop()
{
    if(is_started_ == false)
    {
        return;
    }
    
    {
        MutexLockGuard lock(mutex_);
        is_started_ = false;
        full_.notifyAll();
    }
    for(size_t i = 0; i != poolSize_; ++i)
    {
        threads_[i]->join();
    }

    while(!queue_.empty())
        queue_.pop();
}
