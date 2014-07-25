#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
void set_nonblock(int fd);
void set_block(int fd);

int main(int argc, const char *argv[])
{
    int fd = open("test.txt", O_RDONLY, 0666);
    set_block(fd);
    if(fd == -1)
        ERR_EXIT("OPEn");
    int fd2 = fcntl(fd, F_DUPFD, 0);
    if(fd2 == -1)
    {
        ERR_EXIT("fcntl");
    }

    char buf[1000] = {0};
    read(fd2, buf, 1000);
    fputs(buf, stdout);
    
    close(fd);
    close(fd2);


    return 0;
}

void set_nonblock(int fd)
{
    int val = fcntl(fd, F_GETFL, 0);
    if(val == -1)
        ERR_EXIT("fcntl");
     val |= O_NONBLOCK;
     if(fcntl(fd, F_SETFL, val) < 0)
     {
        ERR_EXIT("fdntl");
     }


}

void set_block(int fd)
{
    int val = fcntl(fd, F_GETFL, 0);
    if(val == -1)
        ERR_EXIT("fcntl");
     val &= ~O_NONBLOCK;
     if(fcntl(fd, F_SETFL, val) < 0)
     {
        ERR_EXIT("fdntl");
     }


}
