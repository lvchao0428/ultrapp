
#include "Queue.h"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    Queue q;
    int num;
    while(cin >> num)
    {
        q.push(num);
    }

    q.print();

    return 0;
}
