/*************************************************************************
	> File Name: test.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 15 Jul 2014 09:14:00 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Test
{
    public:
        void setValue(const string &s, int a)
        {
            s_ = s;
            a_ = a;
        }
        static void draw()
        {
            cout<<"draw"<<endl;
        }

        void print() const
        {
            cout<< s_ << " " << a_<<endl;
        }
    private:
        string s_;
        int a_;
};


int main(int argc, const char *argv[])
{
    void (*func)() = &Test::draw;
    func();
    Test t;
    void (Test::*func2)(const string &, int)  = &Test::setValue;

    void (Test::*func3)() const= &Test::print;
    (t.*func2)("hello", 23);

    Test *pt = &t;

    (pt->*func3)();
    return 0;
}
