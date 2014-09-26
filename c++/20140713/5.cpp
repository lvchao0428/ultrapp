/*************************************************************************
	> File Name: 5.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sun 13 Jul 2014 02:14:59 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class X
{
    friend class Y;
    friend void print(const X &x);
private:
    int x_;
    int y_;
public:
    X(): x_(5), y_(6){}

    void set_x(int x)
    {
        x_ =  x;
    }
    void set_y(int y)
    {
        y_ = y;
    }
};

class Y
{
public:
    void print(const X &x)
    {
        cout<<x.x_<<endl;
        cout<<x.y_<<endl;
    }
};

void print(const X &x)
{
    cout<<x.x_<<endl;
    cout<<x.y_<<endl;
}

int main(int argc, const char *argv[])
{
    X x1;
    Y y1;
    
    y1.print(x1);
    print(x1);

    return 0;
}
