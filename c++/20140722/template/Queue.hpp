
#ifndef QUEUE_H_
#define QUEUE_H_ 

#include <iostream>
#include <stddef.h>
#include <assert.h>

template <typename T>
class Queue;
using namespace std;
template <typename T>
class Node
{
    friend class Queue<T>;
    private:
        T data_;
        Node<T> *next_;
};


template <typename T>
class Queue
{
    public:

        Queue();
        Queue(const Queue &other);
        ~Queue();

        Queue &operator=(const Queue &other);

        void push(T data);
        void pop();
        T top() const ;
        void clear();
        bool isEmpty() const;
        size_t getSize() const;
        void print();
    private:

        
        Node<T>* head_;
        Node<T> * rear_;
        size_t size_;
};

template <typename T>
inline Queue<T>::Queue():
    head_(NULL),rear_(NULL),size_(0)
{
    
}

template <typename T>
inline Queue<T>::Queue(const Queue &other):
    head_(NULL),rear_(NULL),size_(0)
{
    

}

template <typename T>
inline Queue<T> &Queue<T>::operator=(const Queue &other)
{
    if(this != &other)
    {
        Node<T> * p = other.head_;
        push(p->data_);
        p = p->next_;


    }

    return *this;
}

template <typename T>
inline void Queue<T>::print()
{
    Node<T> * p = head_;

    while(p)
    {
        cout<<p->data_<<" ";
        p = p->next_;
    }
}

template <typename T>
inline void Queue<T>::push(T data)
{
    Node<T> * p =new Node<T>;
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

template <typename T>
inline void Queue<T>::pop()
{
    assert(!isEmpty());

    Node<T> * p = head_;
    head_ = head_->next_;

    delete p;
}

template <typename T>
inline T Queue<T>::top() const
{
    return head_->data_;
}

template <typename T>
inline void Queue<T>::clear()
{
    while(!isEmpty())
    {
        pop();
    }
}

template <typename T>
inline bool Queue<T>::isEmpty() const
{
    return head_ == NULL;
}

template <typename T>
inline size_t Queue<T>::getSize() const
{
    return size_;
}

template <typename T>
inline Queue<T>::~Queue()
{
    clear();
}





#endif  /*QUEUE_H_*/

