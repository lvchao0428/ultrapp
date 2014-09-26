
#include <iostream>
#include <string>

using namespace std;

class Person
{
    public:
        Person()
            :id_(-1), name_(""), age_(0)
        {

        };
        Person(int id, const string &name, int age)
            :id_(id), name_(name), age_(age)
        {
        
        }

        void set(int id, const string &name, int age)
        {
            id_ = id;
            name_ = name;
            age_ = age;
        }

        void print() const
        {
            cout << "id="<< id_ << " name=" << name_ << 
                " age=" << age_ <<endl;    
        }
    protected:
        int id_;
        string name_;
        int age_;
};

class Student : public Person
{
    private:
        string school_;

    public:

        void set(int id,
                const string &name,
                int age,
                const string &school)
        {
            
            id_ = id;
            name_ = name;
            age_ = age;
            school_ = school;
        }
    
        void print() const
        {
            cout<<"test"<<endl;
        }
        void test()
        {
            cout<<"tst"<<endl;
        }

};

int main(int argc, const char *argv[])
{
    Student s;
    Person *ptr;
    ptr = &s;
    
    ptr->set(12, "zhangsam", 22);
    ptr->print();

    return 0;
}
