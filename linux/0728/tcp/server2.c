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

void do_service(int peerfd)
{
    char recvbuf[1024];
    int ret;
    while(1)
    {
        memset(recvbuf, 0, sizeof recvbuf);
        ret = read(peerfd, recvbuf, 1000);
        if(ret == -1)
        {
            if(errno == EINTR)
                continue;
            return;
        }
        else if(ret == 0)
        {
            break;
        }
        else
        {
            write(peerfd, recvbuf, sizeof recvbuf);
        }
    }
}

int main(int argc, const char *argv[])
{
    

    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    if(listenfd == -1)
        ERR_EXIT("socket");

    int on = 1;
    if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof on) < 0)
        ERR_EXIT("setsockopt");

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8989);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof servaddr) < 0)
        ERR_EXIT("bind");

    if(listen(listenfd, SOMAXCONN) < 0)
        ERR_EXIT("listen");

    int peerfd;

    if((peerfd = accept(listenfd, NULL,NULL)) < 0)
        ERR_EXIT("accept");

    do_service(peerfd);

    close(peerfd);
    close(listenfd);

    return 0;
}
