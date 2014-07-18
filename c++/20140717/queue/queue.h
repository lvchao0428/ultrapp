#ifndef QUEUE_
#define QUEUE_ 



#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>
#include <stddef.h>
using namespace std;

class Node
{
    public:
        friend class Queue;
    private:
        int num_;
        Node *next_;        
};

typedef Node *Nodeptr;
class Queue
{
    public:
        Queue();
        ~Queue();
        Queue(const Queue &q);

        int top();
        void push(int num);
        void pop();
        bool isEmpty()  const;
        int size();
        Queue &operator = (const Queue &q);


    private:
        Nodeptr head_;
        Nodeptr rear_;
        size_t size_;
};

#endif  /*UEUE_*/
