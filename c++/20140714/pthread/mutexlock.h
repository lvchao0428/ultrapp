/*************************************************************************
	> File Name: mutexlock.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 14 Jul 2014 07:55:12 PM CST
 ************************************************************************/

#ifndef MUTEX_LOCK_H_
#define MUTEX_LOCK_H_

#include <pthread.h>
#include <stdexcept>

class MutexLock
{
    public:
        MutexLock()
        {
            if(pthread_mutex_init(&lock_, NULL))
            {
                throw std::runtime_error("init lock failed");
            }
        }

        ~MutexLock()
        {
            if(pthread_mutex_destroy(&lock_))
            {
                throw std::runtime_error("destroy lock failed");
            }
        }

        void lock()
        {
            if(pthread_mutex_lock(&lock_))
            {
                throw std::runtime_error("lock failed!");
            }
        }

        void unlock()
        {
            if(pthread_mutex_unlock(&lock_))
            {
                throw std::runtime_error("unlock failed!");
            }
        }

        pthread_mutex_t *getMutexLockPtr()
        {
            return &lock_;
        }
    private:
        pthread_mutex_t lock_;
};

#endif
