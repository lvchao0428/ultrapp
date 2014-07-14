/*************************************************************************
	> File Name: queue.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 14 Jul 2014 02:46:09 PM CST
 ************************************************************************/

#include "queue.h"
#include <assert.h>

QUEUE::QUEUE():rear_(NULL),head_(NULL),size_(0)
{
    
}

QUEUE::~QUEUE()
{
    clear();
}

void QUEUE::push(int data)
{
    NODE *pt = new NODE;

    pt->data_ = data;
    pt->next_ = NULL;

    if(isempty())
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

void QUEUE::pop()
{
    NODE *pt = head_;
    head_ = head_->next_;
    size_--;
    delete pt;
}

int QUEUE::top() const
{

    return head_->data_;
}

void QUEUE::clear()
{
    while(!isempty())
    {
        pop();
    }
}

bool QUEUE::isempty()const
{
    return head_ == NULL;
}

size_t QUEUE::getsize()const
{
    return size_;
}

