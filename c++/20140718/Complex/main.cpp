
#include "Complex.h"
#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    Complex c1, c2, c3, c4;
    
    while(cout<<"enter complex:", cin >> c1 >> c2 >> c3 >> c4)
    {
        cout<<"c1:"<<c1<<endl;
        cout<<"c2:"<<c2<<endl;
        cout<<"c3:"<<c3<<endl;
        cout<<"c4:"<<c4<<endl;
        
        cout<<"c1 + c2: " << c1 + c2<<endl;
        cout<<"c2 - c3: " << c2 - c3<<endl;
        cout<<"c3 * c4: " << c3 * c4<<endl;
        cout<<"c4 / c1: " << c4 / c1 <<endl;

    }
    
    return 0;
}
