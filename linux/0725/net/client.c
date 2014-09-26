#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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
#include "readfile.h"


#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)


static void do_service(int fd)
{
    struct pack recvbuf;
    struct pack sendbuf;

    memset(&recvbuf, 0x00, sizeof recvbuf);
    memset(&sendbuf, 0x00, sizeof sendbuf);

    while(fgets(sendbuf.data, MAXLINE, stdin) != NULL)
    {
        int nlen = strlen(sendbuf.data);
        sendbuf.len = htonl(nlen);
        writen(fd, &sendbuf, nlen + sizeof(int));

        int nread = readn(fd, &recvbuf.len, 4);
        if(nread < 0)
        {
            ERR_EXIT("nread");
        }
        if(nread < 4)
        {
            fprintf(stdout, "peer close\n");
            break;
        }

        fprintf(stdout, "len:%d\n", nlen);
        nread = readn(fd, recvbuf.data, nlen);

        if(nread < 0)
            ERR_EXIT("nread");

        if(nread == 0)
        {
            fprintf(stdout, "peer close\n");
            break;
        }
        fprintf(stdout, "recv:%s\n", recvbuf.data);
        memset(&recvbuf, 0x00, sizeof recvbuf);
        memset(&sendbuf, 0x00, sizeof sendbuf);
    }

}


int main(int argc, const char *argv[])
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0)
    {
        ERR_EXIT("socket")    ;
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8989);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    socklen_t len = sizeof(servaddr);

    int ret = connect(fd, (struct sockaddr*)&servaddr, len);
    if(ret < 0)
        ERR_EXIT("CONNECT");

    do_service(fd);

    close(fd);
    return 0;

}
