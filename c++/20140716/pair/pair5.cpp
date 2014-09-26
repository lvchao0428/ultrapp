
/*************************************************************************
	> File Name: pair5.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 09:15:39 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <typeinfo>

using namespace std;

void print(const map<string, int>::value_type &p)
{
    cout<<p.first<<"occurs:"<<p.second<<"times"<<endl;
}

int main(int argc, const char *argv[])
{
    map<string, int> word_count;
    string word;

    while( cin >> word)
    {
        word_count[word]++;
    }

    for_each(word_count.begin(), word_count.end(), print);
    return 0;
}
