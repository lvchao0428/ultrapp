/*************************************************************************
	> File Name: pair2.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 08:14:21 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

class Student
{
    private:
        int num_;
        string name_;

}

int main(int argc, const char *argv[])
{
    std::map<int, int> m1;
    std::map<string, int> m2;
    
    map<string, string> m3;
    map<string, vector<string> > m4;

    map<list<vector<list<string> > > , stack<queue<int> > m5;
    map<int, Student> m6;
    map<Student, int> m7;


    return 0;
}
