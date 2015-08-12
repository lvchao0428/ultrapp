/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: 2015年08月11日 星期二 23时02分11秒
 ************************************************************************/

#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int **p = new int*[3];
    for(int i = 0; i < 3; ++i)
    {
        p[i] = new int[3];
    }

    for(int i = 0; i != 3; ++i)
    {
        for(int j = 0; j != 3; ++j)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i != 3; ++i)
    {
        delete[]p[i];
    }
    delete []p;

    return 0;
}
