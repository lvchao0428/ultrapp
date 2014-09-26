/*************************************************************************
	> File Name: vector.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 02:59:52 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

 using namespace std;

int main(int argc, const char *argv[])
{
    vector<int> vec;

    vec.push_back(23);
    vec.push_back(10);
    vec.push_back(22);
    vec.push_back(99);


    for(vector<int>::size_type ix = 0;
            ix != vec.size(); ++ix)
    {
        cout<<vec[ix]<<' ';
    }
    cout<<endl;

    string s;
    vector<string> vecs;

    while(cin >> s)
    {
        vecs.push_back(s);
    }

    for(vector<string>::iterator it = vecs.begin();
            it != vecs.end(); ++it)
    {
        cout<<*it<<endl;
    }

    return 0;
}
