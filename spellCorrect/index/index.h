#ifndef INDEX_H_
#define INDEX_H_ 

#include <iostream>
#include <string>
#include <vector>
#include "rank.h"

class WordIndex
{
    public:
        WordIndex();
        void fill_Index(std::vector<WORDPAIR> vecw);
    private:
        std::vector<WORDPAIR> vecIndex_[26];
};

#endif  /*INDEX_H_*/
