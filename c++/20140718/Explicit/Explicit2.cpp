
#include "Integer.h"

using namespace std;

void print(const Integer &t)
{
    cout<<t<<endl;
}

int main(int argc, const char *argv[])
{
    Integer t(100) ;

    print(t);

//    print(100);
    return 0;
}
