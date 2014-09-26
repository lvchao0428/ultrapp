/*************************************************************************
	> File Name: Queue.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 14 Jul 2014 02:46:09 PM CST
 ************************************************************************/

#include "Queue.h"
#include <assert.h>

Queue::Queue():rear_(NULL),head_(NULL),size_(0)
{
    
}

Queue::~Queue()
{
    clear();
}

void Queue::push(int data)
{
    Node *pt = new Node;

    pt->data_ = data;
    pt->next_ = NULL;

    if(isEmpty())
    {
        head_ = rear_ = pt;
    }
    else
    {
        rear_->next_ = pt;
        rear_ = pt;
    }
    size_++;
}

void Queue::pop()
{
    assert(!isEmpty());
    Node *pt = head_;
    head_ = head_->next_;
    size_--;
    delete pt;
}

int Queue::top() const
{
    assert(!isEmpty());
    return head_->data_;
}

void Queue::clear()
{
    while(!isEmpty())
    {
        pop();
    }
}

bool Queue::isEmpty()const
{
    return head_ == NULL;
}

size_t Queue::getSize()const
{
    return size_;
}

