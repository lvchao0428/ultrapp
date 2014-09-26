
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int val;

    val = fcntl(STDIN_FILENO, F_GETFL, 0);
    if(val == -1)
        ERR_EXIT("fcntl");

    val |= O_NONBLOCK;

    if(fcntl(STDIN_FILENO, F_SETFL, val) < 0)
        ERR_EXIT("FCNTL:SET");

    char buf[100];
    int ret = read(STDIN_FILENO, buf, 100);
    if(ret == -1)
    {
        ERR_EXIT("fcntl");
    }



    return 0;
}
