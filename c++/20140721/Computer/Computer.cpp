
#include "Computer.h"
#include <iostream>

using namespace std;

Computer::Computer():
    name_(""),
    cost_(0),
    weight_(0)
{}

Computer::Computer(const string &name,
        int cost,
        int weight):
    name_(name),cost_(cost),
    weight_(weight)
{

}


void Computer::set(const string &name,
        int cost, int weight)
{
    name_ = name;
    cost_ = cost;
    weight_ = cost;
}

void Computer::printmsg()
{
    cout<<"name:"<<name_<<" cost:"<<cost_<<" weight:"<<weight_<<endl;

}

int Computer::price()
{
    cout<<"price:"<<cost_<<endl;
}


