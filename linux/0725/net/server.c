#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "readfile.h"

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define MAXLINE 1023    




static void do_service(int peerfd)
{
//    char recvbuf[MAXLINE + 1];

//    memset(recvbuf, 0x00, sizeof(recvbuf));
    
    struct pack recvpac;
    memset(&recvpac, 0x00, sizeof recvpac);

    while(1)
    {
        int nread = read(peerfd, &recvpac.len, MAXLINE);
        if(nread<0)
            ERR_EXIT("nread");

        if(nread < 4)
        {
            fprintf(stdout, "peerclose\n");
            break;
        }
        int nlen = ntohl(recvpac.len);

        fprintf(stdout, "len:%d", nlen);

        nread = readn(peerfd, recvpac.data, nlen);
        if(nread < 0)
            ERR_EXIT("wread");

        if(nread < nlen)
        {
            fprintf(stdout, "peer close\n");
            break;
        }
        
        fprintf(stdout, "recv:%s", recvpac.data);

        writen(peerfd, &recvpac, 4 + nlen);

        memset(&recvpac, 0x00, sizeof recvpac);
    }
}

int main(int argc, const char *argv[])
{
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0)
        ERR_EXIT("socket");
    
    int on = 1;
    if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on,
                sizeof(on)) < 0)
        ERR_EXIT("SETSOCKOPT");

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8989);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    socklen_t len = sizeof servaddr;
    int ret = bind(listenfd, (struct sockaddr*)&servaddr, len);

    if(ret < 0)
        ERR_EXIT("bind");

    ret = listen(listenfd, SOMAXCONN);
    if(ret < 0)
        ERR_EXIT("LISTEN");

    struct sockaddr_in peeraddr;
    bzero(&peeraddr, sizeof peeraddr);
    len = sizeof peeraddr;
    int peerfd = accept(listenfd, (struct sockaddr*)&peeraddr, &len);
    if(peerfd < 0)
        ERR_EXIT("accept");

    fprintf(stdout, "IP=%s, port=%d\n", inet_ntoa(peeraddr.sin_addr),
            ntohs(peeraddr.sin_port));
    do_service(peerfd);

    close(peerfd);
    close(listenfd);

    

    return 0;
}
