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

    private:
        string name_;
        int age_;
        int score_;
};

int main(int argc, const char *argv[])
{
    Student s;
    s.set("lule", 12, 99);

    Student s2(s);

    s2.print();


    return 0;
}

