#ifndef INDEX_H_
#define INDEX_H_ 

#include <iostream>
#include <string>
#include <vector>

class WordIndex
{
    public:
        void fill_Index(std::vector<std::string> vecw);
        void print();
    private:
        std::vector<std::string> vecIndex_[26];
};

#endif  /*INDEX_H_*/
