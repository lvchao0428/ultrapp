/************************************************************************
	> File Name: queue.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 14 Jul 2014 02:32:39 PM CST
 ************************************************************************/

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class QUEUE;
class NODE
{
    public:
        friend class QUEUE; 
    private:
        
        int data_;
        NODE *next_;
        
};


class QUEUE
{
    public:
        QUEUE();
        ~QUEUE();

        void push(int data);
        void pop();
        int top()const;
        void clear();
        bool isempty()const;
        size_t getsize()const;

        friend void *producer(void* arg);
        friend void *consumer(void* arg);
    private:
        
        NODE *rear_;
        NODE *head_;
        size_t size_;
        
};


#endif
