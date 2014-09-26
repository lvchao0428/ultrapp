#include "SmartPtr.h"

using namespace std;

int main(int argc, const char *argv[])
{
    SmartPtr ptr(new Animal);
    (*ptr).run();
    ptr->run();
    return 0;
}
