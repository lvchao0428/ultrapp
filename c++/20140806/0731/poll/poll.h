
#ifndef SELECT_H_
#define SELECT_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <poll.h>

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

typedef struct
{
    struct pollfd clients_[2048];
    int max_;
    int listenfd_;
    int nready_;

    void (*handle_callback_)(int, char*);
}poll_t;

void poll_init(poll_t *pol,int listenfd);

int poll_do_wait(poll_t *pol);

void poll_handle_accept(poll_t *pol);

void poll_handle_data(poll_t *pol);

void poll_set_callback(poll_t *sel, 
        void (*handle_callback)(int, char*));




#endif  /*SELECT_H_*/
