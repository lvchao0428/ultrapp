/*************************************************************************
	> File Name: inline.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 03:10:22 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T> 
inline void swap1(T &a,T &b)
{
    T temp(a);
    a = b;
    b = temp;
}

int main(int argc, const char *argv[])
{
    int a, b;
    string s1, s2;
    double d1, d2;
    int n;
    
    while(cout<<"enter &n,(1 for int, 2 for string, 3 for double)"<<endl,cin>>n)
    {
        switch(n)
        {
            case 1:
                cin>>a>>b;
                cout<<"a = "<<a<<", b = "<<b<<endl;
                swap1(a, b);
                cout<<"a = "<<a<<", b = "<<b<<endl;
                break;
            case 2:
                cin>>s1>>s2;
                cout<<"s1 = "<<s1<<", s2 = "<<s2<<endl;
                swap1(s1, s2);
                cout<<"s1 = "<<s1<<", s2 = "<<s2<<endl;
                break;
            case 3:
                cin>>d1>>d2;
                cout<<"d1 = "<<d1<<", d2 = "<<d2<<endl;
                swap1(d1, d2);
                cout<<"d1 = "<<d1<<", d2 = "<<d2<<endl;
                break;
        }
    }

    return 0;
}
