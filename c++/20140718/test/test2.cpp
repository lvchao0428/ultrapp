
#include <stdexcept>
#include <iostream>
#include "SmartPtr.h"
using namespace std;


int main(int argc, const char *argv[])
{
    try
    {
        Animal *ps = new Animal[3];
        throw runtime_error("error");

        delete[] ps;
    }
    catch(runtime_error &e)
    {
        cout<<e.what()<<endl;
    }

    return 0;
}
