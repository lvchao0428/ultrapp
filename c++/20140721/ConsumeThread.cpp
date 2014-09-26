/*************************************************************************
	> File Name: ConsumeThread.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 15 Jul 2014 03:07:38 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "ConsumeThread.h"
#include "Buffer.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

ConsumeThread::ConsumeThread(Buffer &buffer)
    :tid_(0), buffer_(buffer)
{
    
}

void ConsumeThread::start()
{
    pthread_create(&tid_, NULL, threadFunc, this);
}

void *ConsumeThread::threadFunc(void *arg)
{
    ConsumeThread *pt = static_cast<ConsumeThread *>(arg);
    pt->run();

    return NULL;
}

void ConsumeThread::run()
{
    while(1)
    {
        srand(time(NULL));
        int data = buffer_.consume();
        cout<<"consume a data "<<data << endl;

        sleep(rand()%3 + 1);
    }
}

void ConsumeThread::join()
{
    pthread_join(tid_, NULL);
}
