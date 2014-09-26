/*************************************************************************
	> File Name: stu.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 09:01:59 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class TSU
{
    public:
        TSU()
        {
            printf("create\n");
        };
        virtual ~TSU()
        {
            printf("destroy\n");
        };
    private:
        
};

int main(int argc, const char *argv[])
{
    TSU a, b;
    return 0;
}
