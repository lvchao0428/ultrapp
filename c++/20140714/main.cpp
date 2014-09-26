/*************************************************************************
	> File Name: main.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 14 Jul 2014 04:11:21 PM CST
 ************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "queue.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int argc, const char *argv[])
{
    QUEUE q;
    srand(time(NULL));
    q.push(rand()%100);
    q.push(rand()%100);
    q.push(rand()%100);
    q.push(rand()%100);
    q.push(rand()%100);
    cout<<q.top()<<" ";
    q.pop();
    cout<<q.top()<<" ";
    q.pop();
    cout<<q.top()<<" ";
    q.pop();
    cout<<q.top()<<" ";
    q.pop();
    cout<<q.top()<<" ";
    q.pop();
    cout<<endl;




    return 0;
}
