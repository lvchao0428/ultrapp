#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <map>
#include <fstream>
using namespace std;
typedef pair<string, int> WORDPAIR;

typedef unordered_map<char, map<string, int> > HASHMAP;



void fill_hash(HASHMAP &wordhash)
{
    string word;
    int num;
    char c;
    string::iterator siter;
    ifstream in;
    in.open("rank_bible.txt");
    if(!in)
        throw runtime_error("cannot open the file");
    while(in >> word >> num)
    {
        siter = word.begin();
        for(; siter != word.end(); ++siter)
        {
            wordhash[*siter].insert(make_pair(word, num));
        }
    }
}

void print(const HASHMAP &hm)
{
    HASHMAP::const_iterator hpit = hm.begin();
    for(; hpit != hm.end(); ++hpit)
    {
        map<string, int>::const_iterator mit = hpit->second.begin();

        for(; mit != hpit->second.end(); ++mit)
        {
            cout << (*hpit).first << " " << mit->first << " "
                << mit->second << endl;
        }
    }
}

int main(int argc, const char *argv[])
{
    HASHMAP wordhash;
    
    fill_hash(wordhash);
    print(wordhash);




    return 0;
}
