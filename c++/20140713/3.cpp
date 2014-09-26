/*************************************************************************
	> File Name: 2.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sun 13 Jul 2014 11:05:58 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
    private:
        int id_;
        string name_;
        int age_;
    public:
        
        Person():
            id_(-1),name_("none"),age_(-1)
        {}
        
        Person(int id, const string &name, int age):
                    id_(id),name_(name),age_(age)
        { }

        Person &set_id(int id)
        {
            id_ = id;
            return *this;
        }
        Person &set_name(const string &name)
        {
            name_ = name;
            return *this;
        }
        Person &set_age(int age)
        {
            age_ = age;
            return *this;
        }

        Person &print(ostream &os)
        {
            os<<"id:"<<id_<<"i name:"<<name_<<" age:"<<age_<<endl;  
        
            return *this;
        }
        
        const Person &print( ostream &os)const
        {
            os<<"id:"<<id_<<"i name:"<<name_<<" age:"<<age_<<endl;
            return *this;
        }
    
};

int main(int argc, const char *argv[])
{
    Person p2(12,"zhangsan", 12345);
    Person p;
    p.set_id(12).print(cout).set_age(22).print(cout).set_name("hello").print(cout);
    p2.print(cout);
    return 0;
}
