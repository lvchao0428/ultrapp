
#include "thread.h"
#include <iostream>
using namespace std;

class FooThread
{
    public:
        FooThread(int i);
        void ThreadFunc();
        void startThread();
        void joinThread();

    private:
        int cnt_;
        Thread Thread_;
};

FooThread::FooThread(int i)
    :cnt_(i),
    thread_(bind(&FooThread::threadFunc, this))
{}
