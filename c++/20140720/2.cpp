
#include <iostream>

using namespace std;

class Base
{
    public:
        Base()
        {
            cout<<"Base create"<<endl;
        }
        ~Base()
        {
            cout<<"recreate the base"<<endl;
        }

};

class Derived:public Base
{
    public:
        Derived()
        {
            cout<<"Derived create"<<endl;
        }
        ~Derived()
        {
            cout<<"recreate the derived"<<endl;
        }
};

int main(int argc, const char *argv[])
{
    Derived d;


    return 0;
}
