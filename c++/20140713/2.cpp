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
        
        Person(int id, const string &name, int age)
        {
            id_ = id;
            name_ = name;
            age_ = age;
        }
        int get_id()const
        {
            return id_;
        }
        void set_id(int id)
        {
            id_ = id;
        }
        string get_name()const
        {
            return name_;
        }
        void set_name(const string &name)
        {
            name_ = name;
        }
        int get_age()const
        {
            return age_;
        }
        void set_age(int age)
        {
            age_ = age;
        }
        void print(ostream &os)
        {
            os<<"id:"<<id_<<"i name:"<<name_<<" age:"<<age_<<endl;
        }
    
};

int main(int argc, const char *argv[])
{
    Person p2(12,"zhangsan", 12345);
    p2.print(cout);
    return 0;
}
