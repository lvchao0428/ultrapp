
#include "def.h"

pool_t::pool_t(size_t size)
{
    size_ = size;
    pthreads_ = new pthread_t[size];
    is_started_ = false;
    pthread_mutex_init(&mutex_, NULL);
    pthread_cond_init(&cond_, NULL);
}

pool_t::~pool_t()
{
    
}

void *pool_t::thread_pool_thread_func(void *arg)
{
    pool_t *pool = static_cast<pool_t *>(arg);
    while(1)
    {
        task_t task;
        bool ret = pool->thread_pool_get_task_from_queue(task);
        if(ret == true)
            task.thread_func_(task.arg_);
        else 
            break;
    }
}

void pool_t::thread_pool_start()
{
    if(is_started_ == false)
    {
        is_started_ = true;
        int i;
        for (i = 0; i < size_; i++) 
        {
            pthread_create(&pthreads_[i],NULL,
                    thread_pool_thread_func, this);
        }
        
    }
}

void pool_t::thread_pool_stop()
{
    if(is_started_ == false)
        return;
    is_started_ = false;

    pthread_cond_broadcast(&cond_);
    int i;
    for (i = 0; i < size_; i++) 
    {
        pthread_join(pthreads_[i], NULL);
    }
    queue_.clear();
    
}

void pool_t::thread_pool_add_task_to_queue(task_t task)
{
    pthread_mutex_lock(&mutex_);
    queue_.push(task);
    pthread_cond_signal(&cond_);
    pthread_mutex_unlock(&mutex_);
}

bool pool_t::thread_pool_get_task_from_queue(task_t &task)
{
    pthread_mutex_lock(&mutex_);
    while(queue_.isEmpty() == true && is_started_ == true)
    {
        pthread_cond_wait(&cond_, &mutex_);
    }

    if(is_started_ == false)
    {
        pthread_mutex_unlock(&mutex_);
        return false;
    }
    task = queue_.top();
    queue_.pop();

    pthread_mutex_unlock(&mutex_);
    return true;
}

bool pool_t::thread_pool_is_started()
{
    return is_started_;
}   

size_t pool_t::thread_pool_get_size_of_queue()
{
    return size_;
}

