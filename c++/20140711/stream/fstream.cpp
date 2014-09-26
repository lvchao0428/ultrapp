/*************************************************************************
	> File Name: fstream.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 09:20:10 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, const char *argv[])
{
    ifstream is("in.txt");

    string word;
    vector<string> vec;
    while(is >> word)
    {
        vec.push_back(word);
    }

    for(vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << endl;    
    }

    return 0;
}
