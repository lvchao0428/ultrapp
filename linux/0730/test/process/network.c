
#include "network.h"

ssize_t readn(int fd, char *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nread;
    char *buf = usrbuf;

    while(nleft > 0)
    {
        if((nread = read(fd, buf, nleft)) == -1)
        {
            if(errno == EINTR)
                nread = 0;
            return -1;
        }else if(nread == 0)
            break;
        
        nleft -= nread;
        buf += nread;

    }

    return (n - nleft);
}

ssize_t writen(int fd, char *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nwrite;
    char *buf = usrbuf;

    while(nleft > 0)
    {
        if((nwrite = write(fd, buf, nleft)) <= 0)
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

ssize_t recv_peek(int sockfd, char *usrbuf, size_t n)
{
    int nread;

    while(1)
    {
        nread = recv(sockfd, usrbuf, n, MSG_PEEK);
        if(nread < 0 && errno == EINTR)
            continue;
        if(nread < 0)
            return -1;

        break;
    }

    return nread;
}

ssize_t readline(int sockfd, char *usrbuf, size_t maxline)
{
    size_t nleft = maxline -1;
    ssize_t nread;
    int ret;
    int total= 0;
    char *buf = usrbuf;

    while(nleft > 0)
    {
        ret = recv_peek(sockfd, buf, nleft);

        if(ret <= 0)
            return ret;

        nread = ret;

        int i;
        for (i = 0; i < nread; i++) 
        {
            if(buf[i] == '\n')
            {
                ret = read(sockfd, buf, i+1);
                if(ret != i+1)
                    return -1;
                total += ret;
                buf += ret;
                *buf = 0;
                return total;
            }
        }

        ret = read(sockfd, buf, nread);
        if(ret <= 0)
            return ret;

        total += ret;
        nleft -= ret;
        buf += ret;

        
    }

    *buf = 0;
    return maxline -1;
}


