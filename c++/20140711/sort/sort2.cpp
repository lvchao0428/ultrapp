/*************************************************************************
	> File Name: sort2.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 08:48:33 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct STU
{
    string name_;
    int score_;
    int age_;

    bool operator< (const STU &other) const
    {
        if(score_ != other.score_)
        {
            return score_ < other.score_;
        }
        else if(age_ != other.age_)
        {
            return age_ < other.age_;
        }
        else
        {
            return name_ < other.name_;
        }
    }
};

int main(int argc, const char *argv[])
{
    STU st[4] = {
        {"jordan", 100, 50},
        {"jame", 99, 40},
        {"bush", 88, 30},
        {"canedi", 88, 22}
    };

    sort(st, st+4);
    int i;
    for (i = 0; i < 4; i++) 
    {
        cout<<st[i].name_<<' '<<st[i].score_<<' '<<st[i].age_<<endl;
    }
    

    return 0;
}
