#include "TcpServer.h"
#include "NonCopyable.h"
#include <iostream>
#include <string>
using namespace std;
using namespace std::placeholders;

class EchoServer : NonCopyable
{
    public:
        EchoServer(const InetAddress &addr)
            :server_(addr)
        {
            server_.setConnection(bind(&EchoServer::onConnect, this, _1));
            server_.setMessage(bind(&EchoServer::onMessage, this,_1));
        }

        void start()
        {
            server_.start();
        }

    private:
        void onConnect(const TcpConnectionPtr &conn)
        {
            conn->sendString("hello\r\n");
            conn->sendString("the Tcp Connetion will be closed~\r\n");
        }

        void onMessage(const TcpConnectionPtr &conn)
        {
            cout<<"recv data"<<conn->receiveString();
            conn->sendString("ACK\r\n");
        }
        TcpServer server_;
};

int main(int argc, const char *argv[])
{
    InetAddress addr(8989);
    EchoServer server(addr);
    server.start();
    return 0;
}
