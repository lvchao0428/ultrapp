
#include "Queue.hpp"

#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, const char *argv[])
{
    Queue<string> p;

    int i;
    for (i = 0; i < 5; i++) 
    {
        p.push("hello");
    }

    for (i = 0; i < 5; i++) 
    {
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;
    
    

    return 0;
}
