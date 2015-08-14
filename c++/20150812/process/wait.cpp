/*************************************************************************
	> File Name: wait.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: 2015年08月12日 星期三 23时26分15秒
 ************************************************************************/

#include<iostream>
#include<unistd.h>
#include<sys/wait.h>

using namespace std;


int main()
{
    int pid, status;
    pid = fork();
    if(pid == 0)
    {
        cout << "child" << endl;
        exit(0);
    }
    else
    {
        wait(&status);
        cout << "parent " << status << endl;
    }

    return 0;
}

