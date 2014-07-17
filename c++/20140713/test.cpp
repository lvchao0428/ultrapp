/************************************************************************
	> File Name: test.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sun 13 Jul 2014 02:30:56 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


using namespace std;

class query;
class WORD
{

private:
    string ww_;
    int num_;
public:
    friend class query;
    WORD(string word, int num)
    {
        ww_ = word;
        num_ = num;
    }

    void set_ww(const string &word)
    {
        ww_  = word;
    }

    string get_ww() const
    {
        return ww_;
    }

    int get_num()const
    {
        return num_;
    }

    void set_num(const int &num)
    {
        num_ = num;
    }


};

class query
{

public:
    void push_backword(const WORD &word)
    {
        words_.push_back(word);
    }
    
    query &invec(const string &word)
    {
        vector<WORD>::iterator it;
        for(it = (*this).words_.begin(); it != (*this).words_.end(); ++it)
        {
            if((*it).ww_ == word)    
            {
                (*it).num_ ++;
                break;
            }
            
        }

        WORD wow(word, 1);
        if(it == words_.end())
            push_backword(wow);
        return *this;
    }

    vector<WORD>::iterator rbeg()
    {
        return words_.begin();
    }

    vector<WORD>::iterator rend()
    {
        return words_.end();
    }
    
private:
    vector<WORD> words_;
};

bool cmp(WORD w1, WORD w2)
{
    return w1.get_num() > w2.get_num();
}

int main(int argc, const char *argv[])
{
    query Q;
    string name;
    while(cout<<"enter name&num:", cin>>name)
    {
        Q.invec(name);
        
        for(vector<WORD>::iterator it = Q.rbeg(); it != Q.rend(); ++it)
        {
            cout<<(*it).get_ww()<<" "<<(*it).get_num()<<endl;
        }


        sort(Q.rbeg(),Q.rend(),cmp);
    }
    return 0;
}
    
