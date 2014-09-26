#include "network.h"
#include <sys/select.h>

int get_listen_fd();
void do_select(int listenfd);

int main(int argc, const char *argv[])
{
    if(signal(SIGPIPE,SIG_IGN) == SIG_ERR)
        ERR_EXIT("signal");

    int listenfd = get_listen_fd();

    do_select(listenfd);

    close(listenfd);

    return 0;
}


int get_listen_fd()
{
    //创建socket
    int listenfd = socket(PF_INET, SOCK_STREAM, 0);
    if(listenfd == -1)
        ERR_EXIT("socket");


    //设置端口复用
    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
        ERR_EXIT("setsockopt");

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8989);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //bind端口
    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof servaddr) < 0)
        ERR_EXIT("bind"); 

    //listen端口
    if(listen(listenfd, SOMAXCONN) < 0)
        ERR_EXIT("listen");

    return listenfd;
}

void do_select(int listenfd)
{
    fd_set allset;
    fd_set rset;
    int clients[FD_SETSIZE];
    int i;
     for (i = 0; i <FD_SETSIZE; i++) 
     {
         clients[i] = -1;
     }
     int maxi = -1;
     int nready;
     int maxfd = listenfd;
     FD_ZERO(&allset);
     FD_ZERO(&rset);
     FD_SET(listenfd, &allset);

     while(1)
     {
        rset = allset;

        nready = select(maxfd + 1, &rset, NULL,NULL,NULL);
        if(nready == -1)
        {
            if(errno == EINTR)
                continue;
            ERR_EXIT("select");
        }else if(nready == 0)
            continue;

        if(FD_ISSET(listenfd, &rset))
        {
            int peerfd = accept(listenfd, NULL,NULL);
            if(peerfd == -1)
                ERR_EXIT("accept");
            int i;
            for (i = 0; i < FD_SETSIZE; i++) 
            {
                if(clients[i] == -1)
                {
                    clients[i] = peerfd;
                    if(i > maxi)
                        maxi = i;
                    break;
                }
            }
            if(i == FD_SETSIZE)
            {
                fprintf(stderr, "too many clients\n");
                exit(EXIT_FAILURE);
            }

            FD_SET(peerfd, &allset);
            if(peerfd > maxfd)
                maxfd = peerfd;
            if(--nready <= 0)
                continue;
        }

        int i;
        for (i = 0; i <= maxi; i++) 
        {
            if(FD_ISSET(clients[i], &rset))
            {
                char recvbuf[1024];
                int fd = clients[i];
                int ret = readline(fd, recvbuf, 1024);
                if(ret == -1)
                    ERR_EXIT("readline");
                else if(ret == 0)
                {
                    printf("client close\n");
                    close(fd);
                    clients[i] = -1;
                    FD_CLR(fd, &allset);
                }

                printf("recv data:%s", recvbuf);
                writen(fd, recvbuf, strlen(recvbuf));

                if(--nready <= 0)
                    break;
            }
        }
        
     }
     

}
