#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <string>
#include <vector>
#include <stddef.h>

using namespace std;

class Node
{
    public:
        friend class Queue; 
    private:
        
        int data_;
        Node *next_;
        
};


class Queue
{
    public:
        Queue();
        ~Queue();

        void push(int data);
        void pop();
        int top()const;
        void clear();
        bool isEmpty()const;
        size_t getSize()const;

    private:
        
        Node *rear_;
        Node *head_;
        size_t size_;
        
};


#endif
