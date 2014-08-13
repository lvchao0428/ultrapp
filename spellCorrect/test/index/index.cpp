#include "index.h"
#include <algorithm>
using namespace std;


void WordIndex::fill_Index(vector<string> vecw)
{
    int i;
    string::iterator itstr;
    vector<string>::iterator itword;
    vector<string>::iterator tmpit;
    for(itword = vecw.begin(); itword != vecw.end(); ++itword)
    {
        for(itstr = (*itword).begin(); itstr != (*itword).end(); ++itstr)
        {
            tmpit = find(vecIndex_[(*itstr) - 'a'].begin(),
                    vecIndex_[(*itstr) - 'a'].end(), *itword);
            if( vecIndex_[] tmpit != vecIndex_[(*itstr) - 'a'].end())
                vecIndex_[(*itstr)-'a'].push_back(*itword);
        }
    }
}

void WordIndex::print()
{
    for(int i = 0; i != 26; ++i)
    {
        if(vecIndex_[i].empty())
            continue;
        vector<string>::iterator it = vecIndex_[i].begin();
        for(; it != vecIndex_[i].end(); ++it)
        {
            cout  << *it << " ";
        }
        cout<<endl;
    }
}
