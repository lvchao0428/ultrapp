#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

ssize_t readn(int fd, char *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nread;
    char *buf = usrbuf;

    while(nleft > 0)
    {
        if((nread = read(fd, buf, nleft)) < 0)
        {
            if(errno == EINTR)
                nread = 0;
            return -1;
        }
        else if(nread == 0)
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
    size_t nleft = maxline - 1;
    ssize_t nread;
    char *buf = usrbuf;
    int ret;
    ssize_t total = 0;

    while(nleft > 0)
    {
        ret = recv_peek(sockfd, buf, nleft);
        if(ret < 0)
            return -1;

        nread = ret;
        int i;
        for (i = 0; i < nread; i++) 
        {
            if(buf[i] == '\n')
            {
                ret = readn(sockfd, buf, i+1);
                if(ret != i+1)
                    return -1;

                total += ret;
                buf += ret;
                *buf = 0;
                return total;
            }
        }
        
        ret = readn(sockfd, buf, nread);
        if(ret != nread)
            return -1;
        nleft -= nread;
        buf += nread;
        total += nread;
    }
    *buf = 0;
    return maxline;
}

void do_service(int peerfd)
{
    char recvbuf[1024] = {0};
    char sendbuf[1024] = {0};

    fd_set readset;
    FD_ZERO(&readset);
    int stdin_fd = fileno(stdin);
    int maxfd = (stdin_fd > peerfd) ? stdin_fd : peerfd;
    int nready;

    while(1)
    {
        FD_ZERO(&readset);
        FD_SET(peerfd, &readset);
        FD_SET(stdin_fd, &readset);

        nready = select(maxfd + 1, &readset, NULL,NULL,NULL);
        if(nready == -1)
        {
            if(errno == EINTR)
                continue;
            ERR_EXIT("SELECT");
        }else if(nready == 0)
            continue;
        else
        {
            if(FD_ISSET(stdin_fd, &readset))
            {
                if(fgets(sendbuf, 1024, stdin) == NULL)
                {
                    shutdown(peerfd, SHUT_WR);
                }
                else
                    writen(peerfd, sendbuf, strlen(sendbuf));
            }

            if(FD_ISSET(peerfd, &readset))
            {
                int ret = readline(peerfd, recvbuf, 1024);
                if(ret == -1)
                    ERR_EXIT("readline");
                else if(ret == 0)
                    return;
                else
                    printf("recv data :%s", recvbuf);
            }
        }


    }
}

int main(int argc, const char *argv[])
{
    int peerfd = socket(PF_INET, SOCK_STREAM, 0);
    if(peerfd == -1)
        ERR_EXIT("SOCKET");

    struct sockaddr_in peeraddr;
    peeraddr.sin_family = AF_INET;
    peeraddr.sin_port = htons(8989);
    peeraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(connect(peerfd, (struct sockaddr*)&peeraddr, 
                sizeof peeraddr))
        ERR_EXIT("CONNECT");

    do_service(peerfd);

    close(peerfd);


    return 0;
}

