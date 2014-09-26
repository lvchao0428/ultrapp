/*************************************************************************
	> File Name: queue.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 12:20:31 AM CST
 ************************************************************************/

#include "queue.h"
#include <stdlib.h>
#include <assert.h>

void queue_init(QUEUE *q)
{
    q->head_ = NULL;
    q->tail_ = NULL;
    q->size_ = 0;
}

void queue_destroy(QUEUE *q)
{
    queue_clear(q);
}
void queue_push(QUEUE *q, int data)
{
    p_node p = (p_node)malloc(sizeof(node));
    p->data_ = data;
    p->next_ = NULL;
    if(queue_is_empty(q))
    {
        q->head_ = q->tail_ = p;
    }
    else
    {
        q->tail_->next_ = p;
        q->tail_ = q->tail_->next_;
    }

    q->size_ ++;
}

int queue_top(const QUEUE *q)
{
    assert(!queue_is_empty(q));
    return q->head_->data_;
}

void queue_pop(QUEUE *q)
{
    assert(!queue_is_empty(q));
    p_node p = q->head_;
    q->head_ = q->head_->next_;
    free(p);
    q->size_ --;
}

void queue_clear(QUEUE *q)
{
    while(!queue_is_empty(q))
    {
        queue_pop(q);
    }
}

int queue_is_empty(const QUEUE *q)
{
    if(q->size_ == 0)
        return 1;
    else
        return 0;
}


