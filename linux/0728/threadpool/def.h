#ifndef DEF_H_
#define DEF_H_ 

#include <stddef.h>
#include <pthread.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0

typedef struct
{
    void (*thread_callback)(void *);
    void *arg_;
}task_t;

typedef struct q_node
{
    task_t data_;
    struct q_node *next_;
}q_node, *p_node;

typedef struct queue
{
    p_node head_;
    p_node rear_;
    size_t size_;
}queue;

typedef struct pool
{
    size_t size_;
    pthread_t *threads_;
    BOOL is_started_;
    queue queue_;
    pthread_cond_t cond_;
    pthread_mutex_t mutex_;
}pool_t;

void queue_init(queue *q);
void queue_destroy(queue *q);
void queue_pop(queue *q);
task_t queue_top(const queue *q);
void queue_push(queue *q, task_t task);
BOOL queue_is_empty(const queue *q);
size_t queue_get_size(const queue *q);

void pool_init(pool_t *pool, size_t size);
void pool_destroy(pool_t *pool);
void pool_start(pool_t *pool);
void pool_stop(pool_t *pool);
void pool_addtasktothepool(pool_t *pool, task_t task);
BOOL pool_gettaskfromthepool(pool_t *pool, task_t *task);
BOOL pool_is_empty(const pool_t *pool);
size_t pool_getsize(const pool_t *pool);





#endif  /*DEF_H_*/
