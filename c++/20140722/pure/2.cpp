
#include <iostream>
#include <string>
#include <vector>   

using namespace std;

class Animal
{
    public:
        virtual void run() = 0;
        virtual ~Animal(){}
};

class Cat: public Animal
{
    public:
        void run()
        {
            cout<<"Cat  "<<endl;
        }


};

int main(int argc, const char *argv[])
{
    Animal *pa = new Cat;

    pa->run();

    delete pa;
    return 0;
}


