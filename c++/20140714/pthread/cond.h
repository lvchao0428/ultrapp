/*************************************************************************
	> File Name: cond.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 14 Jul 2014 09:14:06 PM CST
 ************************************************************************/

#ifndef COND_H_
#define COND_H_

#include <pthread.h>
#include <stdexcept>


class Condition
{
    public:
        Condition()
        {
            if(pthread_cond_init(&con_,NULL ))
            {
                throw std::runtime_error("condtion ");
            }
        }

        ~Condition()
        {
            if(pthread_cond_destroy(&con_)) 
            {
                throw std::runtime_error("destroy condition");
            }
        }

        void wait()
        {
            if(pthread_cond_wait(&con_, lock_.getMutexLockPtr()))
            {
                throw std::runtime_error("wait ");
            }
        }

        void signal()
        {
            if(pthread_cond_signal(&con_))
            {
                throw std::runtime_error("signal");
            }
        }

        void notifyall()
        {
            if(pthread_cond_broadcast())
            {
            
            }
        }
    private:
        pthread_cond_t con_;
        MutexLock &lock_;
}

#endif
