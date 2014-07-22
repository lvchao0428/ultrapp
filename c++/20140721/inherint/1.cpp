
#include <iostream>
#include <string>

using namespace std;
class Person
{
    protected:
        int id_;
        string name_;
        int age_;
    public:
        void set(int id, const string &name, int age)
        {
            id_ = id;
            name_ = name;
            age_ = age;
        }
        void print()
        {
            cout<<id_<<name_<<age_<<endl;
        }
};

class Student:public Person
{
    private:
        string school_;
    public:
        void set(int id, const string &name,
                int age, const string &school)
        {
            id_ = id;
            name_ = name;
            age_ = age;
            school_ = school;
        }

        void print()
        {
            cout<<id_<<name_<<age_<<school_<<endl;
        }
};

int main(int argc, const char *argv[])
{
    
    Student s;
    s.Person::set(12, "jordan", 23);

    s.print();
    return 0;
}
