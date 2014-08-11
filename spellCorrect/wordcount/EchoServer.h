#ifndef ECHO_TCP_SERVER_H
#define ECHO_TCP_SERVER_H 

#include <echo/TcpServer.h>
#include <echo/NonCopyable.h>
#include <echo/ThreadPool.h>
#include "TextQuery.h"
#include "wordRank.h"

class EchoServer : NonCopyable
{
    public:
        EchoServer(const InetAddress &addr);
        void start();
    private:
        void onConnection(const TcpConnectionPtr &conn);
        void onMessage(const TcpConnectionPtr &conn);
        void onClose(const TcpConnectionPtr &conn);

        void compute(const std::string &s, const TcpConnectionPtr &conn,
                TextQuery tq);
        int min_ed(const string &s1, const string &s2,
                int m, int n);
        std::vector<WORDPAIR> vecRank_;
        TcpServer server_;
        ThreadPool pool_;
};



#endif  /*ECHO_TCP_SERVER_H*/
