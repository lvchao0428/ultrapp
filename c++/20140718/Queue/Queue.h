#ifndef QUEUE_H_
#define QUEUE_H_ 

#include <stddef.h>

class Node
{
    friend class Queue;
    private:
        int data_;
        Node *next_;
};

typedef Node *Nodeptr;

class Queue
{
    public:
        Queue();
        Queue(const Queue &q);

        Queue &operator=(const Queue &other);
        void push(int data);
        void pop();
        int top() const;
        void clear();
        bool isEmpty() const;
        size_t getSize() const;
        void print();
        ~Queue();
    private:
        Nodeptr head_;
        Nodeptr rear_;
        size_t size_;
};

#endif  /*QUEUE_H_*/
