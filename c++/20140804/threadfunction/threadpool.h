#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_ 

#include "NonCopyable.h"
#include "MutexLock.h"
#include "Condition.h"
#include "PtrVector.h"
#include <queue>
#include <functional>

class Thread;

class Threadpool : private NonCopyable
{
    public:
        typedef std::function<void()> Task;

        Threadpool(size_t queueSize, size_t poolSize);
        ~Threadpool();

        void start();
        void stop();

        void addTask(const Task &);
        Task getTask();

    private:
        void runInThread();

        mutable MutexLock mutex_;
        Condition empty_;
        Condition full_;
        size_t queueSize_;
        std::queue<Task> queue_;
        size_t poolSize_;
        PtrVector<Thread> threads_;
        bool is_started_;
};

#endif  /*THREAD_POOL_H_*/
