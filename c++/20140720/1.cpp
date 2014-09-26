
#include <iostream>
#include <string>

using namespace std;

class Person
{
    private:
        int id_;
        int age_;
        string name_;
    public:
        Person():id_(0) ,name_("none"),age_(-1)
    {}
        Person(int id, const string &name, int age):
            id_(id),name_(name), age_(age)
    {}
        void print(ostream &os) const
        {
            os << "id:"<<id_<<"name:"<<name_<<"age:"<<age_<<endl;
        }
};


class Student: public Person
{
    private:
        string school_;
    public:
        void test()
        {
            cout<<"stst"<<endl;

        }
        
        void print(ostream &os) const
        {
            os<<"print"<<endl;
            Person::print(os);
        }
        
        void print()const
        {
            cout<<"jordan"<<endl;
            Person::print(cout);
        }
};

class Worker: public Person
{
    private:
        string factory_;
};

int main(int argc, const char *argv[])
{
    Student s;
    s.print();
    s.print(cout);
    return 0;
}




