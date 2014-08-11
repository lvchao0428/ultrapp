#ifndef RANK_H_
#define RANK_H_ 

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <utility>
#include <stdexcept>

typedef std::pair<std::string, int >  WORDPAIR;

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
};

#endif  /*RANK_H_*/
