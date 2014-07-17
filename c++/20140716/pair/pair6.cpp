/*************************************************************************
	> File Name: pair6.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 09:18:31 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

void print(const map<string, int>::value_type &p)
{
    cout<<p.first<<"occurs: "<<p.second<<"times "<<endl;
}

int main(int argc, const char *argv[])
{
    map<string, int> word_count;
    string word;

    word_count.insert(map<string, int>::value_type("hello", 1));
    for_each(word_count.begin(), word_count.end(), print);

    cout<<"-----------"<<endl;
    word_count.insert(make_pair("test", 3));
    for_each(word_count.begin(), word_count.end(), print);
    
    pair<map<string, int>::iterator, bool> ret = 
        word_count.insert(map<string, int>::value_type("hello", 4));

    for_each(word_count.begin(), word_count.end(), print);

    cout<<"----------"<<endl;

    cout<<ret.first->first<<endl;

    cout<<ret.first->second<<endl;

    cout<<ret.second<<endl;


    return 0;
}
