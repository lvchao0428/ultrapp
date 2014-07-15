#ifndef FACTORY_H_
#define FACTORY_H_ 

#include <vector>
#include "Buffer.h"
#include "ProduceThread.h"
#include "ConsumeThread.h"
class Factory
{
    public:
        Factory(size_t bufferSize_, 
                size_t producerNum_,
                size_t consumerNum_);

        void start();
        virtual ~Factory();
    private:
        size_t buffersize_;
        Buffer buffer_;
        size_t producerNum_;
        size_t consumerNum_;
        std::vector<ProduceThread> produceThreads_;
        std::vector<ConsumeThread> consumeThreads_;

};

#endif  /*FACTORY_H_*/
