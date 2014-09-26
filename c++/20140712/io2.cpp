/*************************************************************************
	> File Name: 2.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 12 Jul 2014 03:29:38 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main(int argc, const char *argv[])
{
    int num = 9;
    cin >> num ;
    cout<< num <<endl;

    cout<<"bad = "<<cin.bad()<<endl;
    cout<<"eof = "<<cin.eof()<<endl;
    cout<<"fail = "<<cin.fail()<<endl;
    cout<<"god = "<<cin.good()<<endl;

    string s = "hello";
     
    cin>>s;
    cout<<s<<endl;
    cout<<"bad = "<<cin.bad()<<endl;
    cout<<"eof = "<<cin.eof()<<endl;
    cout<<"fail = "<<cin.fail()<<endl;
    cout<<"god = "<<cin.good()<<endl;
    return 0;
}
