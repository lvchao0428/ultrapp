#include "EchoServer.h"
#include "wordRank.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include "TextQuery.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <map>
#include <set>
#include <fstream>
#include <stdexcept>

using namespace std;
using namespace placeholders;

ifstream infile;
TextQuery tq;
WordRank wr("rank_bible.txt");

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

int EchoServer::min_ed(const string &s1, const string &s2, int m , int n)
{
    int dis = 0, temp = 0;
    if(m!=0 && n!= 0)
    {
        if(s1[m-1] == s2[n-1])
            dis =  min_ed(s1, s2, m-1, n-1);
        else
        {
            dis =  min_ed(s1, s2, m, n-1) + 1; 
            if((temp = min_ed(s1, s2, m-1, n) + 1) < dis)
                dis = temp;
            if((temp = min_ed(s1, s2, m-1, n-1)+1) < dis)
                dis = temp;
        }
    }
    return dis;
}


ifstream& open_file(ifstream &in, const string &file)
{
    in.close();
    in.clear();
    in.open(file.c_str());
    return in;
}

EchoServer::EchoServer(const InetAddress &addr)
    :server_(addr),
    pool_(1000, 4)
{
    server_.setConnection(bind(&EchoServer::onConnection, this, _1));
    server_.setMessage(bind(&EchoServer::onMessage, this, _1));
    server_.setClose(bind(&EchoServer::onClose, this, _1));
//    open_file(infile, "bible.txt");
//    tq.read_file(infile);
    

}

void EchoServer::start()
{
    pool_.start();
    server_.start();
}

void EchoServer::onConnection(const TcpConnectionPtr &conn)
{
    cout << conn->getPeerAddr().toIp() << " port: "
        << conn->getPeerAddr().toPort() << endl;
    conn->send("Hello, welcome to Echo Server!!!\r\n");
   
}


void EchoServer::onMessage(const TcpConnectionPtr &conn)
{

    string s(conn->receive());
    s = s.erase(s.size()-2);
    cout<<s<<endl;   
    pool_.addTask(bind(&EchoServer::compute, this, s, conn, tq));
}

void EchoServer::compute(const std::string &word,const TcpConnectionPtr &conn,
        TextQuery tq)
{
    set<TextQuery::line_no> locs = tq.run_query(word);
   // print_results(locs, s, tq);
    string line;
    typedef set<TextQuery::line_no> line_num;
    line_num::size_type size = locs.size();
    char ssize[100];
    sprintf(ssize, "%d", size);
    //conn->send(line);
    line_num::const_iterator it = locs.begin();
    for(; it != locs.end(); ++it)
    {
        char sit[128];
        sprintf(sit, "%d",(*it) + 1);
        line = line +  "\t(line " + sit + " )" + tq.text_line(*it) + "\n";
    }
    line += "\n" + word + " occurs " + ssize + " " + 
        make_plural(size, "time", "s") + "\n";

    cout<<line<<endl; 
    conn->send(line);


  
}     

void EchoServer::onClose(const TcpConnectionPtr &conn)
{
    cout << conn->getPeerAddr().toIp() << " port: "
        << conn->getPeerAddr().toPort() << "Close" << endl;
    conn->shutdown();
}



