#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>

using namespace std;

typedef pair<string, int> WORDPAIR;

typedef unordered_map<uint32_t, map<string, int> > HASHMAP;


typedef struct Node
{
    WORDPAIR wp_;

    WORDPAIR fill(pair<string, int> p)
    {
        wp_.first = p.first;
        wp_.second = p.second;
    }
    bool operator<(const Node &other)
    {
        return wp_.second < other.wp_.second;
    }
}Node;



int main(int argc, const char *argv[])
{
    HASHMAP hm;
    priority_queue<WORDPAIR>  pq;  
    string word;
    int num;
    char c;
    Node nd;
    nd.fill(make_pair("apple", 100));
    hm['a'].insert(nd.wp_);
    nd.fill(make_pair("air", 100));
    hm['a'].insert(nd.wp_);
    nd.fill(make_pair("app", 100));
    hm['a'].insert(nd.wp_);
    nd.fill(make_pair("altra", 100));
    hm['a'].insert(nd.wp_);
    
    HASHMAP::iterator hit = hm.begin();
    while(hit != hm.end())
    {
        map<string, int>::iterator mit = hit->second.begin();
        for(; mit != hit->second.end(); mit++)
        {
            pq.push(*mit);
        }

        hit++;
    }

    while(!pq.empty())
    {
        cout << pq.top().first << " "
            << pq.top().second << endl;
        pq.pop();
    }


    return 0;
}
