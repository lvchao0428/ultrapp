/*************************************************************************
	> File Name: 1.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sun 13 Jul 2014 10:55:54 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person
{
    int _id;
    string _name;
    int _age;

    void print(ostream &os)
    {
        os << "id:"<<_id<<"name:"<<_name<<"age:"<<_age<<endl;
    }
};

int main(int argc, const char *argv[])
{
    Person p1;
    p1._age = 99;
    p1._id = 0123;
    p1._name = "jack";

    Person *p2 = new Person;
    p2->_age = 34;
    p2->_id = 12345;
    p2->_name = "hello";
    p2->print(cout);
    p1.print(cout);
    return 0;
}
