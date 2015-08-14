/*************************************************************************
	> File Name: fork.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: 2015年08月12日 星期三 23时09分33秒
 ************************************************************************/

#include<iostream>
#include<unistd.h>
using namespace std;

int main()
{
    int pid;
    cout << "hello main process"<<endl;
    if((pid = fork()))
    {
        cout << pid << " hello main porcess" << endl;
    }
    else
    {
        cout << pid << " hello child process " << endl;
    }

    return 0;
}

