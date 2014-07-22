
#ifndef CONSUME_H_
#define CONSUME_H_ 

#include <pthread.h>
#include "Thread.h"
class Buffer;
//inherit must use .h file
class Consume:public Thread
{
    public:
        Consume(Buffer &buffer);
        void run();
        
};

#endif  /*CONSUME_H_*/
