/*************************************************************************
	> File Name: mapbible.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 17 Jul 2014 09:32:07 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <map>
#include <fstream>
#include <stdexcept>
using namespace std;

ifstream &open_file(ifstream &in, const string &filename)
{
    in.close();
    in.clear();
    in.open(filename.c_str());
    return in;
}

void print(map<string, int>::value_type &p)
{
    cout<<p.first<<" occurs: "<<p.second<<" times."<<endl;
}

int main(int argc, const char *argv[])
{
    ifstream in;
    open_file(in, argv[1]);
    vector<make_pair(string, int) > 
    if(!in)
    {
        throw runtime_error("cannot open the file");
    }
    map<string, int> word_count;
    string word;
    while(in >> word)
    {
        word_count[word]++;
    }
    
    cout<<"input complete"<<endl;

    int n, k;
    map<string, int>::iterator it;
    while(cout<<"enter mode:", cin>>n)
    {
        switch(n)
        {
            case 1:
                while(cout<<"enter word you want to search:",cin >> word)
                {
                    it = word_count.find(word);
                    if(it == word_count.end())
                    {
                        cout<<"not exist."<<endl;
                    }
                    else
                    {
                        cout<<it->first<<" occurs:"<<it->second<<endl;
                    }
                }
            case 2:
                cout<<"enter the k:";
                cin>>k;
                
                map<string, int>::iterator it = word_count.begin();
                while(k > 0)
                {
                    it++;
                    k--;
                }

                for_each(word_count.begin(), it, print);

                break;
        }
    }
    return 0;
}
