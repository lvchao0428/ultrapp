
#include "thread.h"
#include <iostream>

using namespace std;

void *threadFunc(void *arg)
{

    cout<<"hello world"<<endl;
}

int main(int argc, const char *argv[])
{
    Thread t(threadFunc);
    t.start();

    t.join();

    return 0;
}
