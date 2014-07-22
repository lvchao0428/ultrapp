
#include <iostream>
#include <stddef.h>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
using namespace std;

ifstream &open_file(ifstream &is, const string &filename)
{
    is.close();
    is.clear();
    is.open(filename.c_str());
    return is;
}

class GT
{
    public:
        GT(size_t val = 0) :
            bound_(val)
        {
            
        }

        bool operator()(const string &s)
        {
            return s.size() >= bound_;
        }
    private:
        string::size_type bound_;
};

int main(int argc, const char *argv[])
{
    vector<string> vec;
    
    ifstream is;
    open_file(is, argv[1]);
    if(!is)
    {
        runtime_error("cannot open the file");

    }

    string word;

    while(is >> word)
    {
        vec.push_back(word);
    }

    cout<<"fill the vec complete..."<<endl;

    vector<string>::size_type wc = std::count_if(vec.begin(),
            vec.end(), GT(6));

    cout<<wc<<" words longer than 6"<<endl;

    return 0;
}
