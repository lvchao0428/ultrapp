/*************************************************************************
	> File Name: io5.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 12 Jul 2014 04:53:30 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main(int argc, const char *argv[])
{
    ifstream is;
    ofstream os;
    is.open("in.txt");
    os.open("out.txt");
    string word;
    while( is >> word)
    {
        os<<word<<' ';
    }
    return 0;
}

