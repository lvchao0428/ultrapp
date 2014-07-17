/*************************************************************************
	> File Name: pair7.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 09:27:05 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void print(const map<string, int>::value_type &p)
{
    cout<<p.first<<" occurs: "<<p.second<<" times "<<endl;
}

int main(int argc, const char *argv[])
{
    map<string, int> word_count;
    string word;

    while(cin>>word)
    {
        pair<map<string, int>::iterator, bool > ret =
            word_count.insert(
                    map<string, int>::value_type(word, 1));
        if(! ret.second)
        {
            ++ret.first->second;
        }
    }

    for_each(word_count.begin(), word_count.end(), print);

    return 0;
}
