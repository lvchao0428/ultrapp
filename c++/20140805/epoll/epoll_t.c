
#include "epoll_t.h"

#include <sys/types.h>
#include <sys/socket.h>

void epoll_add_fd(epoll_t *epol, int fd);
void epoll_del_fd(epoll_t *epol, int fd);

void epoll_init(epoll_t *epol,
        int listenfd,
        void (*handler)(int ,char *))
{
    if((epol->epollfd_ = epoll_create(2048)) == -1)
        ERR_EXIT("epoll_create");
    epol->nready_ = 0;
    epol->listenfd_ = listenfd;
    epoll_add_fd(epol, listenfd);
    epol->handle_callback_ = handler;
}

void epoll_close(epoll_t *epol)
{
    close(epol->epollfd_);
    close(epol->listenfd_);
}

void epoll_do_wait(epoll_t *epol)
{
    int nready;
    do
    {
        nready = epoll_wait(epol->epollfd_, 
                            epol->events_,
                            2048,
                            -1);
    }while(nready == -1 && errno == EINTR);

    if(nready == -1)
        ERR_EXIT("epoll");
    epol->nready_ = nready;
}

void epoll_handle(epoll_t *epol)
{
    int i;
    for (i = 0; i < epol->nready_; i++) 
    {
        int fd = epol->events_[i].data.fd;
        if(fd == epol->listenfd_)
            epoll_handle_accept(epol);
        else
            epoll_handle_data(epol, fd);
    }
    
}

void epoll_handle_accept(epoll_t *epol)
{
    int peerfd = accept(epol->listenfd_, NULL,NULL);
    if(peerfd == -1)
        ERR_EXIT("accept");
    epoll_add_fd(epol, peerfd);
}


void epoll_add_fd(epoll_t *epol, int fd)
{
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events = EPOLLIN;
    if(epoll_ctl(epol->epollfd_, EPOLL_CTL_ADD,fd, &ev) == -1)
        ERR_EXIT("epoll_ctl");
}

void epoll_del_fd(epoll_t *epol, int fd)
{
    struct epoll_event ev;
    ev.data.fd = fd;
    if(epoll_ctl(epol->epollfd_, EPOLL_CTL_DEL, fd, &ev) == -1)
        ERR_EXIT("epoll_ctl");
}

void epoll_handle_data(epoll_t *epol, int peerfd)
{
    char recvbuf[1024];
    int ret = readline(peerfd, recvbuf, 1024);
    if(ret == -1)
        ERR_EXIT("readline");
    else if(ret == 0)
    {
        printf("client close\n");
        epoll_del_fd(epol, peerfd);
        return;
    }

    epol->handle_callback_(peerfd, recvbuf);
}



