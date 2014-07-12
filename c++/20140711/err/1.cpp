/*************************************************************************
	> File Name: 1.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 09:09:30 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

int main(int argc, const char *argv[])
{
    int i = 5;
    int j = 1;
    int res;
    cout<<"before try ..."<<endl;
    try
    {
        if(j == 0)
        {
            throw exception();
        }
        else
        {
            res = i/j;
        }
        cout<<"dfe"<<endl;
    }
    catch(exception &e)
    {
        cout<<"enter catch...."<<endl;
        cout<<e.what()<<endl;

    }
    cout<<"after try catch..."<<endl;

}
