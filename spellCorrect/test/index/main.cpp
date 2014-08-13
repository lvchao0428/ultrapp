#include <iostream>
#include <string>
#include <vector>
#include "index.h"
using namespace std;

int main(int argc, const char *argv[])
{
    vector<string> vec;
    string word;
    while(cin >> word)
    {
        vec.push_back(word)    ;
    }
    WordIndex wi;
    wi.fill_Index(vec);
    wi.print();


    return 0;
}
