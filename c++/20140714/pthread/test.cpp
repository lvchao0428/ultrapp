/*************************************************************************
	> File Name: test.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 14 Jul 2014 09:51:32 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class A
{
    public:
        friend class B;
        void print()
        {
            cout<<"hello world"<<endl;
        }
    private:

        
};

class B
{
    public:
        friend void print();
        
    private:
        A a;
};

void print()
{
    cout<<"how are you"<<endl;
}

int main(int argc, const char *argv[])
{
    B b;
    A a;
    a.print();
    print();
     



    return 0;
}
