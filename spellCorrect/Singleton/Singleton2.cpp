/*************************************************************************
	> File Name: Singleton.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 15 Jul 2014 09:28:47 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Singleton
{
    public:
        static Singleton *getInstance()
        {
            if(pInstance_ == NULL)
            {
                sleep(1);
                pInstance_ = new Singleton;
            }
            return pInstance_;
        }
    private:
        Singleton(){}

        static Singleton *pInstance_;
        
};

Singleton *Singleton::pInstance_ = NULL;

void *threadFunc(void *arg)
{
    Singleton *ps = Singleton::getInstance();
    cout<<ps<<endl;

    return NULL;
}

int main(int argc, const char *argv[])
{
    vector<pthread_t> vec(10);

    for(vector<pthread_t>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        pthread_create(&*it, NULL, threadFunc, NULL);
    }

    for(vector<pthread_t>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        pthread_join(*it, NULL);
    }

    return 0;
}
