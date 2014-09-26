/*************************************************************************
	> File Name: 4.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sun 13 Jul 2014 02:00:18 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account
{
    public:
        Account()
        {
            ++sum_;
        }
        ~Account()
        {
            --sum_;
        }
        static int show_num();
    private:
        static int sum_;
};

int Account::sum_ = 0;
int Account::show_num()
{
    return sum_;
}

int main(int argc, const char *argv[])
{
    Account a1,a2,a3;

    cout<<a3.show_num()<<endl;
    
    return 0;
}
