
#include <stdexcept>
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    try
    {
        int *p = new int[10];
         
        throw runtime_error("error");

        delete []p;
    }
    catch(runtime_error &e)
    {
        cout << e.what()<<endl;
    }

    return 0;
}
