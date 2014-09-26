
#include "network.h"
#include <pthread.h>

void do_service(int peerfd);
int get_listen_fd();
void *thread_func(void *arg);

int main(int argc, const char *argv[])
{
    if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)
        ERR_EXIT("SIGNAL");

    int listenfd = get_listen_fd();

    while(1)
    {
        int peerfd = accept(listenfd, NULL, NULL);
        if(peerfd == -1)
            ERR_EXIT("accept");

        int *pfd = (int *)malloc(sizeof(int));
        if(pfd == NULL)
            ERR_EXIT("malloc");
        *pfd = peerfd;
        pthread_t tid;
        if(pthread_create(&tid, NULL, thread_func, pfd))
        {
            free(pfd);
        }


    }

    close(listenfd);

    return 0;
}

void *thread_func(void *arg)
{
    int *pfd = (int *)arg;
    int peerfd = *pfd;
    free(pfd);

    pthread_detach(pthread_self());

    do_service(peerfd);
    close(peerfd);
}

int get_listen_fd()
{
    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    if(listenfd == -1)
        ERR_EXIT("SOCKET");

    int on = 1;
    if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on,
                sizeof(on)) < 0)
        ERR_EXIT("SETSOCKOPT");

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8989);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if(bind(listenfd, (struct sockaddr*)&servaddr, 
                sizeof servaddr) < 0)
        ERR_EXIT("BIND");

    if(listen(listenfd, SOMAXCONN) < 0)
        ERR_EXIT("LISTEN");

    return listenfd;
}

void do_service(int peerfd)
{
    char recvbuf[1024] = {0};

    int ret;
    while(1)
    {
        ret = readline(peerfd, recvbuf, 1024);
        if(ret == 0)
        {
            close(peerfd);
            exit(EXIT_SUCCESS);
        }

        printf("recvdata:%s", recvbuf);
        writen(peerfd, recvbuf, strlen(recvbuf));
    }
}
