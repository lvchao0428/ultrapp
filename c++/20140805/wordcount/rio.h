#ifndef NETWORK_H_
#define NETWORK_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)



class Rio : NonCopyable
{
    public:
        Rio(int ,void*,size_t);
        ~Rio();
        ssize_t readn();
        ssize_t writen();
        ssize_t recv_peek();
        ssize_t readline();

    private:
        int fd_;
        void *usrbuf_;
        size_t n;
};




#endif  /*NETWORK_H_*/
