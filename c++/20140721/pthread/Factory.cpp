/*************************************************************************
	> File Name: Factory.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 15 Jul 2014 04:51:02 PM CST
 ************************************************************************/

#include "Factory.h"

#include <vector>


Factory::Factory(size_t bufferSize,
                 size_t producerNum,
                 size_t consumerNum)
    :bufferSize_(bufferSize),
    buffer_(bufferSize_),
    producerNum_(producerNum),
    consumerNum_(consumerNum),
    produceThreads_(producerNum_, Produce(buffer_)),
    consumeThreads_(consumerNum_, Consume(buffer_))
{}

void Factory::start()
{
    for(vector<Produce>::iterator it = produceThreads_.begin(); it != produceThreads_.end(); ++it)
    {
        it->start();
    }

    for(vector<Consume>::iterator it = consumeThreads_.begin(); it != consumeThreads_.end(); ++it)
    {
        it->start();
    }

    for(vector<Produce>::iterator it = produceThreads_.begin(); it != produceThreads_.end(); ++it)
    {
        it->join();
    }

    for(vector<Consume>::iterator it = consumeThreads_.begin(); it != consumeThreads_.end(); ++it)
    {
        it->join();
    }
}
