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


#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define MAXLINE 1023

static void do_service(int fd)
{
    char recvbuf[MAXLINE + 1];
    char sendbuf[MAXLINE + 1];
    memset(recvbuf, 0x00, sizeof recvbuf);
    memset(sendbuf, 0x00, sizeof sendbuf);

    while(fgets(sendbuf, MAXLINE, stdin) != NULL)
    {
        int nwrite = write(fd, sendbuf, strlen(sendbuf));
        if(nwrite < 0)
        {
            ERR_EXIT("WRITE");
        }
        int nread = read(fd, recvbuf, MAXLINE);
        if(nread < 0)
            ERR_EXIT("READ");
        if(nread == 0)
        {
            fprintf(stdout, "peer close\n");
            break;
        }
        fprintf(stdout, "recv:%s\n", recvbuf);
        memset(recvbuf, 0x00, sizeof recvbuf);
        memset(sendbuf, 0x00, sizeof sendbuf);
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
