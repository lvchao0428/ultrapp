
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base
{
    public:
        virtual void print() const
        {
            cout<<"In Base"<<endl;
        }
    private:
        int a_;
};

class Derived : public Base
{
    public:
        void print() const
        {
            cout<<"In Derived "<<endl;
        }
    private:
        int b_;
};

int main(int argc, const char *argv[])
{
    Base *pb = new Derived;

    pb->print();

    cout<<"sizeof Base"<<sizeof(Base)<<endl;
    cout<<"sizeof Derived"<<sizeof(Derived)<<endl;

    delete pb;



    return 0;
}
