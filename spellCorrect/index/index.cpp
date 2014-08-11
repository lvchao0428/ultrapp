#include "index.h"

using namespace std;

WordIndex::WordIndex()
{
    
}

void WordIndex::fill_Index(vector<WORDPAIR> vecw)
{
    int i;
    vector<string>::iterator itstr;
    vector<WORDPAIR>::iterator itword;
    for(itword = vecw.begin(); itword != vecw.end(); ++itword)
    {
        for(itstr = (*itword).begin(); itstr != (*itword).end(); ++itstr)
        {
            vecIndex_[(*it)-'a'].push_back(*itword);
        }
    }
}

void WordIndex::print(int n)
{
    vector<WORDPAIR>::iterator it = vecIndex_[n].begin();
    for(; it != vecIndex_[n].end(); ++it)
    {
        cout << "word:" << it.first << " frequency:" << it.second << endl;
    }
}
