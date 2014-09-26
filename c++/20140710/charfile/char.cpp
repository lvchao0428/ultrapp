/*************************************************************************
	> File Name: char.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 03:20:25 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
       
typedef struct STU
{
    int score;
    string name;
}STU;

int main(int argc, const char *argv[])
{
    STU st;
    vector<STU> vec, vec_good;
    size_t ix = 0;
    while(cin>>st.score>>st.name)
    {
        vec.push_back(st);
        if(st.score >= 60)
            vec_good.push_back(st);
    }

    for(vector<STU>::iterator it = vec_good.begin();
            it != vec_good.end(); ++it)
    {
        cout<<it->name<<' '<<(*it).score<<endl;
    }

    
    return 0;
    
}
