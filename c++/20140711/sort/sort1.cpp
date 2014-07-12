/*************************************************************************
	> File Name: sort1.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 08:18:22 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main(int argc, const char *argv[])
{
    srand(time(NULL));

    vector<int> vec;

    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);
    vec.push_back(rand()%100);

    sort(vec.begin(), vec.end(), cmp);
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout<<*it<<' ';
    }           
    cout<<endl;

    return 0;
}
