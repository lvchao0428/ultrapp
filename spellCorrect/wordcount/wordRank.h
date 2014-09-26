#ifndef WORD_RANK_H_
#define WORD_RANK_H_ 


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

typedef std::pair<std::string, int> WORDPAIR;

class WordRank
{
    public:
        WordRank(const std::tring &s);
        void read_file();


    private:
        std::vector<WORDPAIR> vecw_;
        std::string filename_;
};

#endif  /*WORD_RANK_H_*/
