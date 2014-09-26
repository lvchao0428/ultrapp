/************************************************************************
	> File Name: queue.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 18 Jul 2014 12:28:13 AM CST
 ************************************************************************/

#include "queue.h"


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
    if(this != &q)
    {
        if(q.isEmpty())
        {
            cout<<"q. is empty"<<endl;
        }
        Nodeptr p = q.head_;
        while(p)
        {

            push(p->num_);
            p = p->next_;
        }
    }
}

int Queue::top()
{
    return head_->num_;
}

void Queue::push(int num)
{
    
    Nodeptr p = new Node;
    p->num_ = num;
    
    if(isEmpty())
        head_ = rear_ = p;
    else
    {
        rear_->next_ = p;
        rear_ = rear_->next_;
    }
    size_++;
}

bool Queue::isEmpty() const
{
    return head_ == NULL;
}

void Queue::pop()
{
    assert(!isEmpty());
    Nodeptr p = head_;
    head_ = head_->next_;
    size_--;
    delete p;
}

int Queue::size()
{
    return size_;
}


Queue &Queue::operator =(const Queue &q)
{
    if(this != &q)
    {
        assert(!q.isEmpty());


        Nodeptr p  = q.head_;
        while( p != NULL)
        {
            push(p->num_);
            p = p->next_;
        }
    }
    return *this;
}



Queue::~Queue()
{
    while(head_ != NULL)
    {
        pop();
    }
}


