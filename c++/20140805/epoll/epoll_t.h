
#ifndef EPOLL_H_
#define EPOLL_H_ 

#include "network.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <sys/epoll.h>
#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

typedef struct
{
    int epollfd_;
    int listenfd_;
    struct epoll_event events_[2048];
    int nready_;
    void (*handle_callback_)(int, char*);
}epoll_t;

void epoll_init(epoll_t *epol,
                int listenfd,
                void (*handler)(int , char*));

void epoll_do_wait(epoll_t *epol);

void epoll_handle(epoll_t *epol);

void epoll_handle_accept(epoll_t *epol);

void epoll_handle_data(epoll_t *epol, int peerfd);

void epoll_close(epoll_t *epol);

#endif  /*SELECT_H_*/
