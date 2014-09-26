/*************************************************************************
	> File Name: word_count.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 17 Jul 2014 03:16:03 PM CST
 ************************************************************************/

void print(map<WORDPAIR>::value_type &p)
{
    cout<<p.first<<" occurs: "<<p.second<<"times."<<endl;
}

WordCount::WordCount(const string &filename)
    :fileName_(filename)
{
    readFile();
}

void WordCount::readFile()
{
    ifstream in;
    in.open(filename.c_str());
    if(!in)
    {
        throw runtime_error("cannot open the file");
    }
    string word;
    while(in >> word)
    {
        words_[word]++;
    }
    map<string , int>::iterator iter = words_.begin();
    while( iter != words_.end())
    {
        vecw_.push_back( make_pair(iter->first, iter->second));
    }
    
}

void WordCount::printtopk(int n) const
{
    vector<WORDPAIR>::iterator iter = vecw_.begin();

    while(n > 0)
    {
        iter ++;
        n--;
    }

    for_each(vecw_.begin(), iter, print);
}

void WordCount::printword(const std::string &word)
{
    
    if(words_.find(word) != words_.end())
    {
        cout<<words_.first<<" "<<words_.second<<endl;
    }
}


