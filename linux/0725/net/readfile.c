
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "readfile.h"
#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

ssize_t readn(int fd, char *usrbuf, size_t n);
ssize_t writen(int fd, char *usrbuf, size_t n);

ssize_t readn(int fd, char *usrbuf, size_t n)
{
    size_t nleft = n;
    size_t nread;
    char *buf = usrbuf;


    while(nleft > 0)
    {
        if((nread = read(fd, buf, nleft)) == -1)
        {
            if(errno == EINTR)
                nread = 0;
            else
            {
                return -1;
            }
        }
        else if(nread == 0)
            break;
        nleft -= nread;
        buf += nread;

    }
    return n - nleft;
}

ssize_t writen(int fd, char *usrbuf, size_t n)
{
    size_t nleft = n;
    size_t nwrite;
    char *buf = usrbuf;

    while(nleft > 0)
    {
        if((nleft = write(fd, buf, n)) > 0)
        {
            if(errno == EINTR)
                nwrite = 0;
            else
                return -1;
        }
        nleft -= nwrite;
        buf += nwrite;
    }

    return n;


}
