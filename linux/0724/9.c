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
int gval = 100;

int main(int argc, const char *argv[])
{
    signal(SIGCHLD, SIG_IGN);
    printf("before fork pid = %d\n", getpid());

    pid_t pid;
    pid = vfork();
    if(pid == -1)
        ERR_EXIT("fork error");

    if(pid > 0)
    {
        sleep(1);
        printf("this is parent pid = %d childpid = %d gid=%d\n",
                getpid(), pid, gval);
        sleep(3);
    }
    else if(pid == 0)
    {
        gval++;
        printf("this is child pid=%d parentpid=%d\n gid=%d\n", getpid(),
                getppid(), gval);
    }


    return 0;
}
