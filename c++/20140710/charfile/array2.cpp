/*************************************************************************
	> File Name: array2.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 08:28:53 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

int main(int argc, const char *argv[])
{
    srand(time(NULL));
    int **a = new int*[5];
    for(size_t i = 0; i != 5; ++i)
    {
        a[i] = new int[5];
        for(size_t j = 0; j != 5; ++j)
        {
            a[i][j] = rand()%100;
        }
    }
    
    int i, j;
    for (i = 0; i < 5; i++) 
    {
        for (j = 0; j < 5; j++) 
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
        

    }
   
    for (int i = 0; i !=  5; i++) 
    {
        delete []a[i];
    }
    delete []a;

    return 0;
}
