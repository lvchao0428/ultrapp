
#include "def.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <assert.h>

queue::queue():
    head_(NULL),
    rear_(NULL),
    size_(0)
{

}

queue::queue(const queue &q):
    head_(NULL),
    rear_(NULL),
    size_(0)
{

}

queue &queue::operator=(const queue &other)
{
    p_node p = other.head_;
    while(p)
    {
        push(p->data_);
        p = p->next_;
    }

    return *this;
}

queue::~queue()
{
    clear();
}

void queue::push(task_t data)
{
    p_node p = new q_node;
    p->data_ = data;

    if(isEmpty())
    {
        head_ = rear_ = p;
    }
    else
    {
        rear_->next_ = p;
        rear_ = rear_->next_;
    }
}

void queue::pop()
{
    assert(!isEmpty());

    p_node p = head_;
    head_ = head_->next_;

    delete p;
}

task_t queue::top() const
{
    return head_->data_;
}

void queue::clear()
{
    while(!isEmpty())
    {
        pop();
    }
}

bool queue::isEmpty() const
{
    return head_ == NULL;
}

size_t queue::getSize() const
{
    return size_;
}



