
#include "Produce.h"
#include "Buffer.h"
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

Produce::Produce(Buffer &buffer):
    Thread(buffer)
{
}

void Produce::run()
{
    while(1)
    {
        int data = rand()%100;
        cout<<"produce a data:"<<data<<endl;
        buffer_.produce(data);

        sleep(rand()%5);
    }

}




