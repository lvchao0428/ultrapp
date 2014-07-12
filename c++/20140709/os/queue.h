/*************************************************************************
	> File Name: queue.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 09 Jul 2014 09:35:17 PM CST
 ************************************************************************/
#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <stddef.h>

typedef struct q_node
{
    int data_;
    struct q_node *next_;
}node, *p_node;

typedef struct
{
    p_node head_;
    p_node tail_;
    size_t size_;
}QUEUE;

void queue_init(QUEUE *q);
void queue_destroy(QUEUE *q);
void queue_push(QUEUE *q, int data);
int queue_top(const QUEUE *q);
void queue_pop(QUEUE *q);
void queue_clear(QUEUE *q);
int queue_is_empty(const QUEUE *q);




#endif
