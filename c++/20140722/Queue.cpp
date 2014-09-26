
#include "Queue.h"
#include <cassert>
#include <iostream>
using namespace std;

Queue::Queue():
    head_(NULL),
    rear_(NULL),
    size_(0)
{

}

Queue::Queue(const Queue &q):
    head_(NULL),
    rear_(NULL),
    size_(0)
{

}
Queue &Queue::operator=(const Queue &other)
{
    Nodeptr p = other.head_;
    while(p)
    {
        push(p->data_);
        p = p->next_;
    }

    return *this;
}

void Queue::print()
{
    Nodeptr p = head_;
    while(p)
    {
        cout<<p->data_<<" ";
        p = p->next_;
    }
}


void Queue::push(int data)
{
    Nodeptr p = new Node;
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
void Queue::pop()
{
    assert(!isEmpty());
    
    Nodeptr p = head_;
    head_ = head_->next_;

    delete p;
}
int Queue::top() const
{
    return head_->data_;
}
void Queue::clear()
{
    while(!isEmpty())
    {
        pop();
    }
}
bool Queue::isEmpty() const
{
    return head_ == NULL;
}
size_t Queue::getSize() const
{
    return size_;
}

Queue::~Queue()
{
    clear();
}

