
#include "Thread.h"
#include "Consume.h"
#include "Buffer.h"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>


using namespace std;


Consume::Consume(Buffer &buffer):
    Thread(buffer)
{
}

void Consume::run()
{
    while(1)
    {
        srand(time(NULL));
        int data = buffer_.consume();
        cout<<"consume a data"<<data<<endl;

        sleep(rand()%3 + 1);
    }
}


