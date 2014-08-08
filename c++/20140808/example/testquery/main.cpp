#include "TextQuery.h"
#include <stdlib.h>
using namespace std;

string make_plural(size_t ctr, 
        const string &word,
        const string &ending)
{
    return (ctr == 1) ? word : word + ending;
}


void print_results(const set<TextQuery::line_no>& locs,
        const string& sought, const TextQuery &file)
{
    typedef set<TextQuery::line_no> line_num;
    line_num::size_type size = locs.size();
    cout << "\n" <<sought<<"occurs"
        <<size <<" "
        <<make_plural(size, "time", "s")<<endl;
    line_num::const_iterator it = locs.begin();
    for(; it != locs.end(); ++it)
    {
        cout<<"\t(line "
            <<(*it)+1<<")"
            <<file.text_line(*it)<<endl;
    }
}

ifstream& open_file(ifstream &in, const string &file)
{
    in.close();
    in.clear();
    in.open(file.c_str());
    return in;
}

int main(int argc, const char *argv[])
{
    ifstream infile;
    if(argc < 2 || !open_file(infile, argv[1]))
    {
        cerr << "No input file" << endl;
        return EXIT_FAILURE;
    }

    TextQuery tq;
    tq.read_file(infile);
    while(true)
    {
        cout<< "enter word to look for, or q to quit";
        string s;
        cin >> s;
        if(!cin || s == "q") break;
        set<TextQuery::line_no> locs = tq.run_query(s);
        print_results(locs, s, tq);
    }
    
    return 0;
}
