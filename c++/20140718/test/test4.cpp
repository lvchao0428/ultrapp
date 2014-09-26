
#include <stdexcept>
#include "SmartPtr.h"

using namespace std;

int main(int argc, const char *argv[])
{
    try
    {
        SmartPtr Ptr(new Animal);
        SmartPtr Ptr1(new Animal);
        SmartPtr Ptr2(new Animal);

        
        throw runtime_error("error");
    }
    catch(runtime_error &e)
    {
        cout<<e.what()<<endl;
    }

    return 0;
}
