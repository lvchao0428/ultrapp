/*************************************************************************
	> File Name: fork2.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: 2015年08月12日 星期三 23时12分46秒
 ************************************************************************/

#include<iostream>
#include<unistd.h>
using namespace std;

int main()
{
    int i, pid;
    i = 0;
    pid = fork();
    if(pid == -1)
    {
        cout << "error" << endl;
    }
    else if(pid == 0)
    {
        for(i = 1; i < 1000; i++)
        {
            cout << "BBB" << endl;
        }
    }
    else
    {
        for(i = 1; i < 1000; ++i)
        {
            cout << "AAA" << endl;
        }
    }


    return 0;
}
