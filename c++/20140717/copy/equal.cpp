/*************************************************************************
	> File Name: equal.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 17 Jul 2014 05:12:31 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
    public:
        Student(string name, int age)
        {
            name_= name;
            age_ = age;
        }
        void print()       
        {
            cout<<name_<<" "<<age_<<endl;
        }
    private:
        string name_;
        int age_;
};

int main(int argc, const char *argv[])
{
    Student s("joarda", 51);
    
    Student s1 = s;
    s.print();

    s1.print();
    return 0;
}
