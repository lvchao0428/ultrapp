#ifndef __BASE_H_
#define __BASE_H_

#include<iostream>
using namespace std;

class base
{
    public:
    base(){ cout << "base";}
};

class component
{
    public:
    component(){ cout << "component"; }
};

class derived : public base
{
    friend class component;
public:
    derived(){cout << "derived";}
private:

    component c;
};


#endif
