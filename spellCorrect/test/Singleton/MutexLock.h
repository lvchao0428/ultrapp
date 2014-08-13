#ifndef MUTEXLOCK_H_
#define MUTEXLOCK_H_ 

#include <pthread.h>
#include <stdexcept>

class MutexLock
{
    public:
        MutexLock()
        {
            if(pthread_mutex_init(&lock_, NULL))
            {
                throw std::runtime_error("lock init failed");
            }
        }

        virtual ~MutexLock()
        {
            if(pthread_mutex_destroy(&lock_))
            {
                throw std::runtime_error("destroy failed");
            }
        }

        void lock()
        {
            if(pthread_mutex_lock(&lock_))
            {
                throw std::runtime_error("lock failed");
            }
        }

        void unlock()
        {
            if(pthread_mutex_unlock(&lock_))
            {
                throw std::runtime_error("unlock failed");
            }
        }
    private:
        pthread_mutex_t lock_;
};

#endif  /*MUTEXLOCK_H_*/
