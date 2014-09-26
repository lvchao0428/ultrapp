/*************************************************************************
	> File Name: test.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 17 Jul 2014 11:25:01 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<string , int> WORDPAIR;

bool cmp(WORDPAIR w1,  WORDPAIR w2)
{
    return w1.second > w2.second;
}

void print(const WORDPAIR &iter)
{
    cout<<iter.first<<" occurs:"<<iter.second<<endl;
}

int main(int argc, const char *argv[])
{
    vector<WORDPAIR> vec;
    string word;
    int n;

    while(cin >> word >> n)
    {
        vec.push_back(make_pair(word, n));
    }
    
    for_each(vec.begin(), vec.end(), print);
    sort(vec.begin(), vec.end(), cmp);
    for_each(vec.begin(), vec.end(), print);





    return 0;
}

