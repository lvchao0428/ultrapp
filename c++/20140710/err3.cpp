/*************************************************************************
	> File Name: err3.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 12:39:52 AM CST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

int main(int argc, const char *argv[])
{
    try
    {
        int num ;
        cin >> num ;
        if(num == 1)
        {
            throw out_of_range("test1");
        }
        else if(num == 2)
        {
            throw invalid_argument("test2");
        }
        else
            throw exception();
    }
    catch(out_of_range &e)
    {
        cout<<"catch a out of range"<<endl;
    }
    catch(invalid_argument &e)
    {
        cout<<"catch a invalid_argument"<<endl;
    }
    catch(...)
    {
        cout<<"default process"<<endl;
    }


    return 0;
}
