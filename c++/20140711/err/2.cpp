/*************************************************************************
	> File Name: 2.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Fri 11 Jul 2014 09:33:49 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

int main(int argc, const char *argv[])
{
    try
    {
        int num;
        cin>>num;
        if(num ==1 )
        {
            throw exception();
        }
        else if(num == 2)
        {
            throw out_of_range("ooooo");
        }
        else if(num == 3)
        {
            throw runtime_error("3");
        }
        else if(num ==4)
        {
            throw logic_error("4");
        }
        else
        cout<<"hello"<<endl;

    }
    catch(out_of_range &e)
    {
        cout<<"out of range"<<endl;
        cout<<e.what()<<endl;
    }
    catch(runtime_error &e)
    {
        cout<<"runtime_error"<<endl;
        cout<<e.what()<<endl;
        
    }
    catch(logic_error &e)
    {
        cout<<"logic error"<<endl;
        cout<<e.what()<<endl;
    }
    catch(exception &e)
    {
        cout<<"exception"<<endl;
        cout<<e.what()<<endl;
    }
    catch(...)
    {
        cout<<"catch a exception"<<endl;
        
    }


    return 0;
}
