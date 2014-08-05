#ifndef THREAD_H_
#define THREAD_H_ 

#include "NonCopyable.h"
#include <pthread.h>
#include <functional>

class Thread : private NonCopyable
{
    public:
        typedef std::function<void ()> ThreadFunc;

        Thread(ThreadFunc func);
        ~Thread();

        void start();
        void join();
    private:
        ThreadFunc callback_;
        pthread_t tid_;
        bool is_Started_;
};

#endif  /*THREAD_H_*/
