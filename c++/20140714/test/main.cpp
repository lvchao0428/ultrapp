/*************************************************************************
	> File Name: main.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 14 Jul 2014 07:38:58 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal
{
    public:
        Animal()
        {
            ++sum;
        }
        ~Animal()
        {
            --sum;
        }

        static void printSum()
        {
            cout<<"sum = "<<sum<<endl;
        }

    private:
        static int sum ;
        int a_;
};

int Animal::sum = 0;
int main(int argc, const char *argv[])
{
    Animal a1, a2;
    Animal::printSum();

    Animal a3, a4, a5;
    Animal::printSum();
    a5.printSum();
    Animal::printSum();

    return 0;
}
