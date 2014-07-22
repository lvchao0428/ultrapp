
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base
{};

class Derived : public Base
{};

int main(int argc, const char *argv[])
{
    Derived d;

    Base *pb = &d;

    Base b;

    Derived *pd = (Derived *)&b;

    Derived *pd2 = (Derived *)pb;

    return 0;
}
