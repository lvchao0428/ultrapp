#ifndef WORDCOUNT_H_
#define WORDCOUNT_H_ 

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <utility>
#include <fstream>


typedef std::pair<std::string ,int> WORDPAIR;

class Word
{
    friend class WordCount;

    private:
        std::string word_;
        int line_no_;
};

class WordCount 
{

    public:
        WordCount(const std::string &filename);
        void readFile();
        void printtopk(int n);
        void printword(const std::string &word);
        void printline(const std::string &line);
    private:
        
        
        std::map<std::string, int> words_;
        std::string fileName_;
        std::vector<std::string> line_;
        std::vector<WORDPAIR> vecw_;

};

#endif  /*WORDCOUNT_H_*/
