/*************************************************************************
	> File Name: pair4.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 09:11:58 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <typeinfo>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, const char *argv[])
{
    map<string, int> word_count ;

    word_count["hello"];

    cout<<word_count.size()<<endl;

    word_count["hello"];

    cout<<word_count.size()<<endl;


    word_count["world"];

    cout<<word_count.size()<<endl;

    return 0;
}

