#ifndef RANK_H_
#define RANK_H_ 

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <utility>
#include <stdexcept>
#include <unordered_map>

typedef std::pair<std::string, int >  WORDPAIR;

typedef std::unordered_map<uint32_t , map<std::string,int> > HASHMAP;

class Rank
{
    public:
        Rank(const std::string &s);
        void readfile();
        void compute();
        void print();
        int min_ed(const std::string &s1, 
                    const std::string &s2, 
                    int m, int n);

    private:
        WORDPAIR wp;
        std::string filename_;
        std::vector<WORDPAIR> vecw_;
        std::vector<WORDPAIR> heapvec_;
        HASHMAP hm_;
};

#endif  /*RANK_H_*/
