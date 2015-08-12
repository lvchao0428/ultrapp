#include "rank.h"
#include "heap.h"
#include <math.h>
using namespace std;

Rank::Rank(const std::string &s)
    :filename_(s)
{
    readfile();
}

int min(int a, int b)
{
    return a < b ? a : b;
}

struct PAIR
{
    pair<string, int> wp_;
    bool operator<(const PAIR &other) const
    {
        return wp_.second < other.wp_.second ;
    }
};

int min_ed1(const string &s1, const string &s2, int m , int n)
{
    int max1 = s1.size();
    int max2 = s2.size();

    int **arr = new int*[max1 + 1];
    int i, j;
    for(i = 0; i< max1 + 1; ++i)
        arr[i] = new int[max2 + 1];

    for(i = 0; i < max1 + 1; ++i)
        arr[i][0] = i;
    for(i = 0; i < max2 + 1; ++i)
        arr[0][i] = i;
    for(i = 1; i < max1 + 1; ++i)
    {
        for(j = 1; j < max2 + 1; ++j)
        {
            int d;
            int temp = min(arr[i-1][j] + 1,
                    arr[i][j-1] + 1);
            if(s1[i-1] == s2[j-1])
                d = 0;
            else
                d = 1;
            arr[i][j] = min(temp, arr[i-1][j-1] + d);
        }
    }

    int dis = arr[max1][max2];

    for(i = 0; i < max1 + 1; ++i)
    {
        delete [] arr[i];
        arr[i] = NULL;
    }
    delete [] arr;
    arr = NULL;

    return dis;
}

void Rank::readfile()
{
    ifstream in;
    in.close();
    in.clear();
    in.open(filename_.c_str());
    if(!in)
        throw runtime_error("cannot open the file.");

    string word;
    int num;
    string::iterator siter;
    while(in >> word >> num)
    {
        siter = word.begin();
        for(; siter != word.end(); ++siter)
        {
            hm_[*siter].insert(make_pair(word, num));
        }
    }

    
}

void Rank::map_Union()
{
    
}

void Rank::compute()
{
    string word;
    vector<WORDPAIR> vec;
    WORDPAIR temp_wp;
    int dis = 100;
    int temp_dis = 0;
    double d = 0;
    while(1)
    {
        cout<<"enter the word you want to search:"<<endl;
        dis = 100;
        temp_dis = 0;
        cin>>word;
        vector<WORDPAIR>::iterator it = vecw_.begin();
        heapvec_.clear();
        for(; it != vecw_.end(); ++it)
        {
            //optimize 1:
            d = fabs((word.size() - (it->first).size())/(double)word.size());
            if(d > 0.3)
                continue;
            
            if((temp_dis =min_ed1(word, it->first, 
                    word.size(), (it->first).size())) < dis)
            {
                dis = temp_dis;
                temp_wp = *it;

            }
            else if( temp_dis == dis)
            {
                if(it->second > temp_wp.second)
                {
                    temp_wp = *it;

                }
            }
            if( fabs((double)dis/word.size()) < 0.5)        
                HeapInsert(heapvec_, temp_wp);          
        }
        if(heapvec_.empty())   
        {
            cout<<"search failed."<<endl;
            continue;
        }
        vector<WORDPAIR>::iterator heapit = heapvec_.begin();
        for(; heapit != heapvec_.begin() + 10 && 
                heapit != heapvec_.end(); ++heapit)
            cout << "top 10 fit words are:" << heapit->first << endl;
          
    }
}

void Rank::print()
{
    cout<< "most fit word is:" << wp.first<<endl;
}

int Rank::min_ed(const std::string &s1, 
        const std::string &s2, 
        int m, int n)
{
    int dis = 0, temp = 0;
    if(m!=0 && n!= 0)
    {
        if(s1[m-1] == s2[n-1])
            dis = min_ed(s1, s2, m-1,n-1);
        else
        {
            dis = min_ed(s1, s2, m, n-1) + 1;
            if((temp = min_ed(s1, s2, m-1, n) + 1) < dis)
                dis = temp;
            if((temp = min_ed(s1, s2, m, n-1) + 1) < dis)
                dis = temp;
        }
    }
    return dis;
}
