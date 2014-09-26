/*************************************************************************
	> File Name: string.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 16 Jul 2014 11:08:37 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
    string s = "helloworld";

    s.insert(2, 5, 's');

    cout<<s<<endl;

    s = "helloworld";

    s.insert(4, "test");
    cout<<s<<endl;

    s = "helloworld";
    
    s.insert(2, "test", 3);
    cout<<s<<endl;
    
    s = "helloworld";
    string _tmp  = "foobar" ;
    s.insert(5, _tmp, 3, 2);
    cout<<s<<endl;

    s = "helloworld";
    string _tmp2 = "foobar";
    s.insert(0, _tmp2);
    cout<<s<<endl;

    string s2 = "helloworld";

    s2.erase(4, 5);

    cout<<s2<<endl;

    return 0;
}
