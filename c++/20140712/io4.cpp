/*************************************************************************
	> File Name: io4.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 12 Jul 2014 03:52:00 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <limits>
using namespace std;

int main(int argc, const char *argv[])
{
    int ival;
    while(cin >> ival, !cin.eof())
    {
        if(cin.bad())
            throw runtime_error("IO sream corrupted");
        if(cin.fail())
        {
            cerr<<"bad data , try again"<<endl;
            cin.clear();

            /*
             *忽略缓冲区中的错误信息
             */
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
        }
    }

    return 0;
}
