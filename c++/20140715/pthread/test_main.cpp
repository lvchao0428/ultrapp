/*************************************************************************
	> File Name: test_main.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 15 Jul 2014 03:37:47 PM CST
 ************************************************************************/

#include "ProduceThread.h"
#include "ConsumeThread.h"
#include "Buffer.h"
#include <iostream>

using namespace std;
//生产者数量， 
void total(size_t pro_n, size_t con_n, size_t buf_n)
{
    Buffer buffer(buf_n);
    size_t npro = pro_n;
    size_t ncon = con_n;
    ProduceThread *ppro = new ProduceThread[pro_n](buffer);
    ConsumeThread *pcon = new ConsumeThread[con_n](buffer);
    
    //start
    while(npro --)
    {
        ppro[npro].start();
    }
    npro = pro_n;
    while(ncon --)
    {
        pcon[ncon].start();
    }
    ncon = con_n;

    //join
    while(npro --)
    {
        ppro[npro].join();
    }
    
    while(ncon --)
    {
        pcon[ncon].join();
    }
}

int main(int argc, const char *argv[])
{

    Factory fac(5, 2, 1);
    fac.start();

    return 0;
}
