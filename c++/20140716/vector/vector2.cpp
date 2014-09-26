/*************************************************************************
	> File Name: vector2.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 09:59:48 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Student
{
    private:
        Student(const Student&);
        Student &operator = (const Student &);
};

int main(int argc, const char *argv[])
{
    vector<Student> vec(10);

    return 0;
}

