
#ifndef PRODUCE_H_
#define PRODUCE_H_ 

#include <pthread.h>
#include "Buffer.h"
#include "Thread.h"


class Produce : public Thread
{
    public:
        Produce(Buffer &buffer);
        void run();
};

#endif  /*PRODUCE_H_*/
