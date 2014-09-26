#ifndef FACTORY_H_
#define FACTORY_H_ 

#include <vector>
#include "Buffer.h"
#include "Thread.h"
#include "Produce.h"
#include "Consume.h"

class Factory
{
    public:
        Factory(size_t bufferSize_, 
                size_t producerNum_,
                size_t consumerNum_);

        void start();
        virtual ~Factory(){}
    private:
        size_t bufferSize_;
        Buffer buffer_;
        size_t producerNum_;
        size_t consumerNum_;
        std::vector<Produce> produceThreads_;
        std::vector<Consume> consumeThreads_;

};

#endif  /*FACTORY_H_*/
