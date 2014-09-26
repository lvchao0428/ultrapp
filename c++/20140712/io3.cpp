/*************************************************************************
	> File Name: 3.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 12 Jul 2014 03:40:55 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    int a;

    if(cin.good())
    {
        cout<<"cin is good"<<endl;
    }

    cout<<"good = "<<cin.good()<<endl;

    while(cin >> a)
    {
        cout<<a<<endl;
    }

    cout<<cin.eof()<<endl;
    cout<<cin.fail()<<endl;
    cin.clear();
    string s = "american";
    cin>>s;
    cout<<s<<endl;

    return 0;
}
