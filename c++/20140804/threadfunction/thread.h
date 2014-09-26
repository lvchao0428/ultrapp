#include "NonCopyable.h"
#include <functional>
#include <pthread.h>

class Thread : private NonCopyable
{
    public:
        typedef std::function<void()> ThreadFunc;
         
        Thread(ThreadFunc callback);
        ~Thread();

        void start();
        void join();

    private:
        static void *threadFunc(void *);

        pthread_t tid_;
        bool is_started_;
        ThreadFunc callback_;
};
