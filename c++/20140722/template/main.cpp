
#include "Queue.hpp"

#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    Queue<int> p;

    int i;
    for (i = 0; i < 5; i++) 
    {
        p.push(i);
    }

    for (i = 0; i < 5; i++) 
    {
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;
    
    

    return 0;
}
