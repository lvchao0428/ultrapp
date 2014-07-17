/*************************************************************************
	> File Name: read_file.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 12 Jul 2014 05:10:56 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

ifstream &open_file(ifstream &is, const string &filename)
{
    is.close();
    is.clear();
    is.open(filename.c_str());
    return is;
}

int main(int argc, const char *argv[])
{
    ifstream infile;
    string inname = "in.txt";

    if(!open_file(infile, inname))
    {
        throw runtime_error("file open failed");
    }

    vector<string> lines;
    string line;
    while(getline(infile, line))
    {
        lines.push_back(line);
    }

    for(vector<string>::iterator it = lines.begin(); it != lines.end(); ++it)
    {
        cout << *it << endl;    
    }
    

    return 0;
}



