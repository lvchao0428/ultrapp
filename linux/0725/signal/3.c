
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

typedef void (*sighandler_t)(int);

void handler(int signum)
{
    printf("ctrl + c\n");
}

int main(int argc, const char *argv[])
{
    sighandler_t old;
    if((old = signal(SIGINT, handler)) == SIG_ERR)
        ERR_EXIT("signal");

    int n = 5;
    do
    {
        n = sleep(n);
    }while(n > 0);

    return 0;
}
