
#ifndef THREAD_H_
#define THREAD_H_ 

#include <pthread.h>

class Buffer;

class Thread
{
    public:
        Thread(Buffer &buffer);
        void start();
        static void *threadFunc(void *arg);
        virtual  void run();
        void join();
    protected:
        pthread_t tid_;
        Buffer &buffer_;
};

#endif  /*THREAD_H_*/
