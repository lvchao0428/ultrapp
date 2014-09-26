/*************************************************************************
	> File Name: wordstring.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 12 Jul 2014 12:42:52 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

ifstream & read_file(const string &filename, ifstream &is,
        istringstream &iss, vector<string> &lines,
        vector<string> &words)
{
    is.open(filename.c_str());
    string line;
    string word;

    while(getline(is, line))
    {
        lines.push_back(line);
        iss.str(line);
        while(iss >> word)
        {
            words.push_back(word);
        }
        iss.clear();
    }
    is.close();
    is.clear();
    return is;
}

int main(int argc, const char *argv[])
{
    ifstream ifs;
    string filename = "in.txt";
    ifstream is;
    istringstream iss;
    vector<string> vec_line;
    vector<string> vec_word;

    read_file(filename, is,iss, vec_line,vec_word);
    
    for(vector<string>::iterator it = vec_word.begin(); it != vec_word.end(); ++it)
    {
        cout << *it << endl;    
    }

    return 0;
}
