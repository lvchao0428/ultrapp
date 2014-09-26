
#include "wordRank.h"

WordRank::WordRank(const string &s)
    :filename_(s)
{
    read_file();
}

void WordRank::read_file()
{
    ifstream in;
    in.open(filename_.c_str());
    if(!in)
        throw runtime_error("cannot open the file");

    string word;
    WORDPAIR wordpair
    while(in >> wordpair.first >> wordpair.second)
    {
        vecw_.push_back(wordpair);
    }


}
