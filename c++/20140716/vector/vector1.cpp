/*************************************************************************
	> File Name: vector1.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 09:58:16 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(int argc, const char *argv[])
{
    const size_t MAX_SIZE = 3;
    string arr[MAX_SIZE] = {"hello", "world", "foobar"};

    vector<string> vec(arr, arr + MAX_SIZE);

    for(vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it << endl;    
    }

    return 0;
}
