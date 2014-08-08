#include "TcpServer.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

void onConnect(const TcpConnectionPtr &conn)
{
    conn->sendString("hello\n");
    conn->sendString("the Tcp connection will be closed!\r\n");
    sleep(5);
}

void onMessage(const TcpConnectionPtr &conn)
{
    cout<<"recv data "<<conn->receiveString();
    conn->sendString("ack\r\n");
}

int main(int argc, const char *argv[])
{
    InetAddress addr(8989);
    TcpServer server(addr);
    server.setConnection(&onConnect);
    server.setMessage(&onMessage);
    server.start();

    return 0;

}
