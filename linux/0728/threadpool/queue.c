
#include "def.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

void queue_init(queue *q)
{
    q->head_ = NULL;
    q->rear_ = NULL;
    q->size_ = 0;
}

void queue_destroy(queue *q)
{
    while(!queue_is_empty(q))
    {
        queue_pop(q);
    }
}

void queue_pop(queue *q)
{
    assert(!queue_is_empty(q));
    p_node pt = q->head_;
    q->head_ = q->head_->next_;
    free(pt);
    --q->size_;
}

task_t queue_top(const queue *q)
{
    assert(!queue_is_empty(q));
    return q->head_->data_;
}

void queue_push(queue *q, task_t task)
{
    p_node pt = (p_node)malloc(sizeof(q_node));
    pt->next_ = NULL;
    pt->data_ = task;
    if(queue_is_empty(q))
    {
        q->head_ = q->rear_ = pt;
    }
    else
    {
        q->rear_->next_ = pt;
        q->rear_ = q->rear_->next_;
    }
    ++q->size_;
}

BOOL queue_is_empty(const queue *q)
{
    return q->head_ == NULL;
}

size_t queue_get_size(const queue *q)
{
    return q->size_;
}



