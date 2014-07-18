#include "String.h"

#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    String s;
    s = "helloworld";
    String s1("how are you");
    
    cout<<s<<endl;;

    cout<<s1<<endl; 
    s += s1;
    cin>>s;
    cout<<s<<endl;

    cout<<s<<endl;
    
    return 0;
}
