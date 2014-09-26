/************************************************************************
	> File Name: word_count.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 17 Jul 2014 10:38:29 AM CST
 ************************************************************************/

#include "word_count.h"
#include "rio.h"

using namespace std;

WordCount::WordCount(const string &filename)
{
   fileName_ = filename;
   readFile();
}

void print(const WORDPAIR &p)
{
    cout<<p.first<<" occurs:"<<p.second<<" times"<<endl;
}

void WordCount::printword(const std::string &word)
{
    if(!words_.count(word))
        cout<< word << " "<< words_.count(word)<<endl;
}

int fill_line()
{
    int ret;
    char buf[1024];
    string s;
    while((ret = readline(fd_, buf, 1024)) > 0)
    {
        s = buf;
        line_.push_back(s);
    }


}

void printline(const string &s)
{
    vector<string>::iterator iter = line_.begin();
    for(; iter != line_.end(); ++iter)
    {
        if(line_[i].find(s) != string::npos)
        {
            cout<<line_[i]<<endl;
        }
    }
}

bool cmp(WORDPAIR wp1,WORDPAIR wp2)
{
    return wp1.second > wp2.second;
}

void WordCount::readFile()
{
    ifstream in;
    in.open(fileName_.c_str());
    if(!in)
    {
        throw runtime_error("cannot open the file");
    }
    

    string word;
    while( in >> word)
    {
        words_[word]++;
    }
    
    map<string, int>::iterator iter = words_.begin();

    while( iter != words_.end())
    {
        vecw_.push_back(make_pair(iter->first, iter->second));
        iter ++;
    }

    sort(vecw_.begin(), vecw_.end(), cmp);
    
}

void WordCount::printtopk(int n)
{
    std::vector<WORDPAIR>::iterator iter = vecw_.begin();

    while(n > 0)
    {
        iter ++;
        n--;
    }

    for_each(vecw_.begin(), iter, print);
    
}

