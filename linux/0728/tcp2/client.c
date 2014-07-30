
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

ssize_t readn(int fd, void *readbuf, size_t n)
{
    size_t nleft = n;
    size_t nread ;
    char *buf = readbuf;
    
    while(nleft > 0)
    {
        if((nread = read(fd, buf, nleft)) == -1)
        {
            if(errno == EINTR)
                nread = 0;
            else
                return -1;
        }
        else if(nread == 0)
            break;

        nleft -= nread;
        buf += nread;
    }

    return (n-nleft);
}

ssize_t writen(int fd, void *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nwrite;

    char *buf = usrbuf;

    while(nleft > 0)
    {
        if((nwrite = write(fd, buf, nleft)) <=0)
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

ssize_t readline(int fd, void *usrbuf, size_t maxlen)
{
    char *buf = usrbuf;
    ssize_t nread;
    size_t nleft = maxlen -1;
    char c;
    while(nleft > 0)
    {
        if((nread = read(fd, &c, 1)) < 0)
        {
            if(errno == EINTR)
                continue;
            return -1;
        }
        else if(nread == 0)
            break;
        *buf++ = c;
    }
    *buf = '\0';
    return maxlen - nleft - 1;
}

void do_service(int peerfd)
{
    char recvbuf[1024] = {0};
    char sendbuf[1024] = {0};

    while(1)
    {
        int ret ;

        if(fgets(sendbuf, 1000, stdin) != NULL)
        {
            int len = strlen(sendbuf);
            int data = htonl(len);
            writen(peerfd, &data, sizeof data);
            writen(peerfd, sendbuf, strlen(sendbuf));

            readn(peerfd, &data, sizeof data);
            len = ntohl(data);
            ret = readn(peerfd, recvbuf, len);
            if(ret == 0)
                break;
            printf("receive data:%s", recvbuf);
        }

        memset(sendbuf, 0, sizeof sendbuf);
        memset(recvbuf, 0, sizeof recvbuf);
    }
}

int main(int argc, const char *argv[])
{
    int peerfd = socket(PF_INET, SOCK_STREAM, 0);
    if(peerfd == -1)
        ERR_EXIT("socket");

    struct sockaddr_in peeraddr;
    peeraddr.sin_family = AF_INET;
    peeraddr.sin_port = htons(8989);
    peeraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if(connect(peerfd, (struct sockaddr*)&peeraddr, sizeof peeraddr) < 0)
        ERR_EXIT("connect");

    do_service(peerfd);
    close(peerfd);
        




    return 0;
}
