
#include "recv_peek.h"

ssize_t recv_peek(int sockfd, void *buf, size_t len)
{
    int nread;
    while(1)
    {
        nread = recv(sockfd, buf, len , MSG_PEEK);
        if(nread < 0 && errno == EINTR)
        {
            continue;
        }
        if(nread < 0)
            return -1;
        break;
    }
    return nread;
}

ssize_t readline(int sockfd, void *buf, size_t maxline)
{
    int nread;
    int nleft;
    char *ptr;
    int ret;
    int total = 0;

    nleft = maxline;
    ptr =  buf;

    while(nleft > 0)
    {
        ret = recv_peek(sockfd, ptr, nleft);
        if(ret < =0)
            return ret;
        
        nread = ret;
        int i;
        for (i = 0; i < nread; i++) 
        {
            if(ptr[i] == '\n')
            {
                ret = readn(sockfd, ptr, i + 1);
                if(ret != i+1)
                    return -1;
                total += ret;
                return total;
            }
        }

        ret = readn(sockfd, ptr, nread);
        if(ret != nread)
            return -1;

        nleft  -= nread;
        total += nread;
        ptr += nread;
    }
}
