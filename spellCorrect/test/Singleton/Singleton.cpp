/*************************************************************************
	> File Name: Singleton.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 15 Jul 2014 09:28:47 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Singleton
{
    public:
        static Singleton *getInstance()
        {
            Singleton *ps = new Singleton;
            return ps;
        }
    private:
        Singleton(){}
        
};

int main(int argc, const char *argv[])
{
    Singleton *ps = Singleton::getInstance();
    cout<<ps<<endl;

    Singleton *ps2 = Singleton::getInstance();
    cout<<ps2<<endl;

    return 0;
}
