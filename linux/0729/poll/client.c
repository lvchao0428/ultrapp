
#include "network.h"
#include <poll.h>

void do_service(int peerfd)
{
    char recvbuf[1024] = {0};
    char sendbuf[1024] = {0};

    struct pollfd client[2];
    client[0].fd = fileno(stdin);
    client[0].events = POLLIN;
    client[1].fd = peerfd;
    client[1].events = POLLIN;
    int maxi = 1;
    int nready;

    while(1)
    {
        nready = poll(client, maxi + 1, -1);
        if(nready == -1)
        {
            if(errno == EINTR)
                continue;
            ERR_EXIT("poll");

        }else if(nready == 0)
            continue;

        if(client[0].revents & POLLIN)
        {
            if(fgets(sendbuf, 1024, stdin) == NULL)
            {
                shutdown(peerfd, SHUT_WR);
                client[0].fd = -1;
            }else
            {
                writen(peerfd, sendbuf, strlen(sendbuf));
            }
        }

        if(client[1].revents & POLLIN)
        {
            int ret = readline(peerfd, recvbuf, 1024);
            if(ret == -1)
                ERR_EXIT("readline");
            else if(ret == 0)
            { 
                printf("server close\n");
                close(peerfd);
                break;
            }
            printf("recv data:%s",recvbuf);
        }

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
    if(connect(peerfd, (struct sockaddr*)&peeraddr, sizeof peeraddr)<0)
        ERR_EXIT("CONNECT");

    do_service(peerfd);

    close(peerfd);
    return 0;
}
