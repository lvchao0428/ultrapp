#include "PollPoller.h"
#include <assert.h>
#include <poll.h>
#include <iostream>

using namespace std;

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

PollPoller::PollPoller(int listenfd)
    :listenfd_(listenfd)
{
    int i;
    for(i = 0; i != 2048; ++i)
        event_[i].fd = -1;
    event_[0].fd = listenfd;
    event_[0].events = POLLIN;
    maxi_ = 0;
    nready_ = 0;
}

void PollPoller::poll()
{
    int ret;
    do
    {
        ret = ::poll(event_, maxi_ + 1, 10000);
    }while(ret == -1 && errno == EINTR);

    if(ret == -1)
        ERR_EXIT("poll");
    nready_ = ret;
    cout<<"poll"<<ret<<endl;
}

void PollPoller::handleAccept()
{
    if(event_[0].revents & POLLIN)
    {
        int peerfd;
        if((peerfd = ::accept(listenfd_, NULL,NULL)) == -1)
            ERR_EXIT("accept");
        cout<<"Accept"<<peerfd;
        handleConnectionEvent(peerfd);
    }
}

void PollPoller::handleData()
{
    int i;
    for(i = 1; i<= maxi_; ++i)
    {
        int peerfd = event_[i].fd;
        if(peerfd == -1)
            continue;
        if(event_[i].revents & POLLIN)
        {
            char buf[100];
            int nread = recv(peerfd, buf, sizeof buf, MSG_PEEK);

            if(nread == -1)
                ERR_EXIT("recv");
            else if(nread == 0)
                handleCloseEvent(i);
            else
                handleMessageEvent(peerfd);
        }
    }
}

void PollPoller::handleConnectionEvent(int peerfd)
{
    int i;
    for(i = 1; i< 2048; ++i)
    {
        if(event_[i].fd == -1)
        {
            event_[i].fd = peerfd;
            event_[i].events = POLLIN;
            if(i > maxi_)
                maxi_ = i;
            break;
        }
    }

    if(i == 2048)
    {
        fprintf(stderr, "too many clients\n");
        exit(EXIT_FAILURE);
    }

    TcpConnectionPtr conn(new TcpConnection(peerfd));
    cout<<"Add peerfd"<<peerfd<<endl;
    pair<TcpIterator, bool> ret = lists_.insert(make_pair(peerfd,conn));
    assert(ret.second == true);

    onConnectionCallback_(conn);
}

void PollPoller::handleMessageEvent(int peerfd)
{
    cout << "HandleMessageEvent"<<peerfd <<endl;
    TcpIterator it  = lists_.find(peerfd);
    assert(it != lists_.end());
    onMessageCallback_(it->second);
}

void PollPoller::handleCloseEvent(int i)
{
    assert(i >= 0 && i < 2048);
    int peerfd = event_[i].fd;
    assert(peerfd != -1);
    event_[i].fd = -1;
    cout<<"Close"<<peerfd<<endl;
    TcpIterator it = lists_.find(peerfd);
    assert(it != lists_.end());
    onCloseCallback_(it->second);
    lists_.erase(it);
}
