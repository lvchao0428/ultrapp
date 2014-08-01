#include "network.h"

void do_service(int peerfd)
{
    char recvbuf[1024] = {0};
    int ret;
    
    while(1)
    {
        ret = readline(peerfd, recvbuf, 1024);

        if(ret <= 0)
        {
            close(peerfd);
            exit(EXIT_SUCCESS);
        }

        printf("recvdata :%s", recvbuf);

        writen(peerfd, recvbuf, strlen(recvbuf));
    }
}

void handler(int sig)
{
    while(waitpid(-1, NULL, WNOHANG) > 0);

    return;
}

int get_listen_fd();

int main(int argc, const char *argv[])
{
    if(signal(SIGPIPE, SIG_IGN) == SIG_ERR)
        ERR_EXIT("signal");

    if(signal(SIGCHLD, handler) == SIG_ERR)
        ERR_EXIT("signal");

    int listenfd = get_listen_fd();

    while(1)
    {
        struct sockaddr_in peeraddr;

        memset(&peeraddr, 0, sizeof(peeraddr));
        socklen_t len = sizeof(peeraddr);
        int peerfd = accept(listenfd, (struct sockaddr*)&peeraddr,
                &len);
        if(peerfd == -1)
            ERR_EXIT("accept");
        pid_t pid;
        if((pid = fork()) < 0)
            ERR_EXIT("fork");
        else if(pid == 0)
        {
            close(listenfd);
            do_service(peerfd);
            exit(EXIT_SUCCESS);
        }
        close(peerfd);
    }
    close(listenfd);


    return 0;
}

int get_listen_fd()
{
    //socket
    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    if(listenfd == -1)
        ERR_EXIT("socket");
    //reuse
    int on = 1;
    if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, 
                sizeof(on)) < 0)
        ERR_EXIT("setsockopt");

    struct sockaddr_in servaddr;
    servaddr.sin_family  = AF_INET;
    servaddr.sin_port = htons(8989);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    //bind
    if(bind(listenfd, (struct sockaddr*)&servaddr, 
                sizeof servaddr) < 0)
        ERR_EXIT("bind");


    //listen
    if(listen(listenfd, SOMAXCONN) < 0)
        ERR_EXIT("listen");

    return listenfd;
    

}
