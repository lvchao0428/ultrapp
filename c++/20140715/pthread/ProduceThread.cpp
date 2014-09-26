/*************************************************************************
	> File Name: ProduceThread.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 15 Jul 2014 03:21:09 PM CST
 ************************************************************************/

#include "ProduceThread.h"
#include "Buffer.h"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

ProduceThread::ProduceThread(Buffer &buffer)
    :tid_(0), buffer_(buffer)
{
    srand(time(NULL));
}

void ProduceThread::start()
{
    pthread_create(&tid_, NULL, threadFunc, this);
}

void *ProduceThread::threadFunc(void *arg)
{
    ProduceThread *pt = static_cast<ProduceThread *>(arg);
    pt->run();

    return NULL;
}

void ProduceThread::run()
{
    while(1)
    {
        int data = rand()%100;
        cout<<"produce a data :"<<data<<endl;
        buffer_.produce(data);

        sleep(rand()%5 );
    }
}

void ProduceThread::join()
{
    pthread_join(tid_, NULL);
}
