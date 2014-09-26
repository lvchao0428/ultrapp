#ifndef DEF_H_
#define DEF_H_ 

#include <pthread.h>
#include <stddef.h>
#include <functional>
#include "NonCopyable.h"

class task_t
{
    friend class q_node;
    friend class queue;
    friend class pool_t;
    public:
    std::function<void(void*)> thread_func_;
        void *arg_;
};

class q_node
{
    friend class queue;
    task_t data_;
    q_node *next_;
};

typedef q_node* p_node;

class queue
{
    public:
        friend class q_node;
        queue();
        queue(const queue &q);

        queue &operator=(const queue &other);
        ~queue();
        void push(task_t data);
        void pop();
        task_t top() const;
        void clear();
        bool isEmpty() const;
        size_t getSize() const;

    private:
        p_node head_;
        p_node rear_;
        size_t size_;
};

class pool_t : private NonCopyable
{
    public:
        pool_t(size_t );
        ~pool_t();
        void thread_pool_start();
        void thread_pool_stop();
        void thread_pool_add_task_to_queue(task_t);
        bool thread_pool_get_task_from_queue(task_t &);
        bool thread_pool_is_started();
        size_t thread_pool_get_size_of_queue();
    private:
        static void *thread_pool_thread_func(void* arg);
        size_t size_;
        pthread_t *pthreads_;
        bool is_started_;
        queue queue_;
        pthread_mutex_t mutex_;
        pthread_cond_t cond_;
};


#endif  /*DEF_H_*/
