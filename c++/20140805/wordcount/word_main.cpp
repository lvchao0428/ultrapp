/*************************************************************************
	> File Name: word_main.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 17 Jul 2014 08:50:38 PM CST
 ************************************************************************/

#include "word_count.h"

using namespace std;

int main(int argc, const char *argv[])
{
    if(argc != 2)
    {
        throw runtime_error("cannot open the file");
    }

    WordCount wc(argv[1]);
    
    int n;

    while(cout<<"enter mode:", cin>>n)
    {
        switch(n)
        {
            case 1:
                int k;
                cout<<"enter ehe k";
                cin >> k;
                wc.printtopk(k);
                break;
            case 2:
                string word;
                cout<<"enter the word you want to search:";
                cin>>word;
                wc.printword(word);
                break;
        }
    }
    
    return 0;
}
