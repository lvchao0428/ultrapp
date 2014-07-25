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

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define MAXLINE 1023    

static void do_service(int peerfd)
{
    char recvbuf[MAXLINE + 1];

    memset(recvbuf, 0x00, sizeof(recvbuf));

    while(1)
    {
        int nread = read(peerfd, recvbuf, MAXLINE);
        if(nread<0)
            ERR_EXIT("read");
        if(nread == 0)
        {
            fprintf(stdout, "peerclose\n");
            break;
        }
        fprintf(stdout, "recv:%s", recvbuf);
        int nwrite = write(peerfd, recvbuf, nread);
        if(nwrite < 0)
            ERR_EXIT("write");
        memset(recvbuf, 0x00, sizeof(recvbuf));
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
