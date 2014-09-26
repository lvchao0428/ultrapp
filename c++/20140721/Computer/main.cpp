
#include <iostream>
#include "Dell.h"
#include "Computer.h"

using namespace std;

int main(int argc, const char *argv[])
{
    Dell d("dell",10000, 8, "alienware");

    d.price();

    d.printmsg();


    return 0;
}
