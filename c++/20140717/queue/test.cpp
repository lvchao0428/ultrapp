/*************************************************************************
	> File Name: test.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 18 Jul 2014 12:40:06 AM CST
 ************************************************************************/

#include "queue.h"

using namespace std;

int main(int argc, const char *argv[])
{
    Queue q;

    int n;
    while(cin >> n)
    {
        q.push(n);
    }
    Queue q1(q);
    Queue q2 = q1;
    while(!q.isEmpty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl; 
    cout<<"q1:"<<endl;
    
    while(!q1.isEmpty())
    {
        cout<<q1.top()<<" ";
        q1.pop();
    }
    
    cout<<endl;
   
    while(!q2.isEmpty()) 
    {
        cout<<q2.top()<<" ";
        q2.pop();
    }
    return 0;
}
