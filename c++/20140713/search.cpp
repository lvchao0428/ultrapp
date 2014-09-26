/*************************************************************************
	> File Name: search1.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sun 13 Jul 2014 03:38:13 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream &open_file(ifstream &is, const string &filename)
{
    is.close();
    is.clear();
    is.open(filename.c_str());
    return is;
}
class Query;

class WORD
{
public:
    friend class Query;
    WORD(string word, int num)
    {
        ww_ = word;
        num_ = num;
    }


    string get_ww()
    {
        return ww_;
    }

    int get_num()
    {
        return num_;
    }

    void set_ww(const string &word)
    {
        ww_ = word;
    }

    void set_num(const int &num)
    {
        num_ = num;
    }
private:
    string ww_;
    int num_;
};

bool cmp(WORD w1, WORD w2)
{
    return w1.get_num() > w2.get_num();
}

class Query
{
public:
    

    vector<WORD>::iterator rbeg()
    {
        return words_.begin();
    }

    vector<WORD>::iterator rend()
    {
        return words_.end();
    }


    void invec(const string &word)
    {

        vector<WORD>::iterator it;
        for(it = words_.begin(); it != words_.end(); ++it)
        {
            if((*it).ww_ == word)
            {
                (*it).num_ ++ ;
                break;
            }
        }
        
        if(it == words_.end())
        {
            cout<<word<<endl;
            WORD wow(word, 1);
            words_.push_back(wow);
        }
    }

    void readFile(const string &name)
    {
        ifstream in;
        open_file(in, name);
        if(!in)
        {
            throw runtime_error("cannot open the file");
        }
        string word;
        int n=0;
        while(in >> word)
        {
            n++;
            invec(word);
            cout<<n<<endl;
        }

        sort(words_.begin(), words_.end(), cmp);

    }
    


    

    Query &queryWord(int num)
    {
        switch(num)
        {
            case 1:// 找前n个数

                int n;
                cout<<"enter n:"<<endl;
                cin>>n;
                for(vector<WORD>::const_iterator it = words_.begin(); 
                        it != words_.begin() + n; ++it)
                {
                    
                    cout << (*it).ww_ << " " << (*it).num_<<endl;    
                }

            case 2:// 输出所在单词
                
                string word;
                cout<<"enter the word:"<<endl;
                cin>>word;
                for(vector<WORD>::const_iterator it = words_.begin(); 
                        it != words_.end(); ++it)
                {
                    if((*it).ww_ == word)
                    {
                        cout<<(*it).ww_<<
                            " "<<(*it).num_<<endl;
                    }
                }

        }
        return *this;
    }

private:
    vector<WORD> words_;
};

int main(int argc, const char *argv[])
{
    string filename = argv[1];
    int n;
    Query Q;
    Q.readFile(filename);
    
    while(cout<<"enter the n",cin>>n)
    {
        Q.queryWord(n);
        
    }



    return 0;
}
