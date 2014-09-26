/*************************************************************************
	> File Name: copy.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 17 Jul 2014 04:18:43 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
    public:
        Student():
            name_(""),
            age_(0),
            score_(0)
        {}
        
        Student(const Student &other)
            :name_(other.name_),
            age_(other.age_),
            score_(other.score_)
        {
            
        }

        void set(const string &name, int age, int score)
        {
            name_ = name;
            age_ = age;
            score_ = score;
        }

        void print() const
        {
            cout<<name_<<" "<<age_<<" "<<score_<<endl;
        }
    
        Student &operator =(const Student &rhs)
        {
            name_ = rhs.name_;
            age_ = rhs.age_;
            score_ = rhs.score_;
        }
    private:
        string name_;
        int age_;
        int score_;
};

int main(int argc, const char *argv[])
{
    Student s;
    s.set("lule", 12, 99);
    s.print();
    Student s2(s);

    s2.print();
    Student s3 = s2;
    s3.print();

    return 0;
}

