
#include "def.h"

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void pool_init(pool_t *pool, size_t size)
{
    pool->size_ = size;
    pool->threads_ = (pthread_t *)malloc(sizeof(pthread_t)* size);
    pool->is_started_ = FALSE;
    queue_init(&pool->queue_);
   
   
    pthread_cond_init(&pool->cond_, NULL);
    pthread_mutex_init(&pool->mutex_, NULL);
}



void pool_destroy(pool_t *pool)
{
    pool_stop(pool);
    free(pool->threads_);
    queue_destroy(&pool->queue_);
    pthread_mutex_destroy(&pool->mutex_);
    pthread_cond_destroy(&pool->cond_);
}

void *pool_thread_func(void *arg)
{
    pool_t *pool = (pool_t *)arg;
    while(1)
    {
        task_t task;
        BOOL ret = pool_gettaskfromthepool(pool, &task) ;
        if(ret)
            task.thread_callback(task.arg_);
        else
            break;
    }
}


void pool_start(pool_t *pool)
{
    if(pool->is_started_ == FALSE)
    {
        pool->is_started_ = TRUE;
        int i;
        for (i = 0; i < pool->size_; i++) 
        {
            pthread_create(&pool->threads_[i], NULL, pool_thread_func, pool);
        }
    }
}

void pool_stop(pool_t *pool)
{
    if(pool->is_started_ == FALSE)
        return;
    pool->is_started_ == FALSE;

    pthread_cond_broadcast(&pool->cond_);

    int i;
    for (i = 0; i < queue_get_size(&pool->queue_); i++) 
    {
        pthread_join(pool->threads_[i], NULL);
    }

    queue_destroy(&pool->queue_);
}

void pool_addtasktothepool(pool_t *pool, task_t task)
{
    pthread_mutex_lock(&pool->mutex_);
    queue_push(&pool->queue_, task);
    pthread_cond_signal(&pool->cond_);
    pthread_mutex_unlock(&pool->mutex_);
}

BOOL pool_gettaskfromthepool(pool_t *pool, task_t *task)
{
    pthread_mutex_lock(&pool->mutex_);
    while(pool->is_started_ == TRUE && 
            queue_is_empty(&pool->queue_))
    {
        pthread_cond_wait(&pool->cond_, &pool->mutex_);
    }

    if(pool->is_started_ == FALSE)
    {
        pthread_mutex_unlock(&pool->mutex_);
        return FALSE;
    }

    *task = queue_top(&pool->queue_);
    queue_pop(&pool->queue_);


    pthread_mutex_unlock(&pool->mutex_);

    return TRUE;

}

BOOL pool_is_started(const pool_t *pool)
{
    return pool->is_started_;
}

size_t pool_getsize(const pool_t *pool)
{
    return queue_get_size(&pool->queue_);
}

