#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    printf("parent process id:%d\n", getpid());
    printf("ppid: %d\n", getppid());
    pid_t iRet = fork();
    if(iRet < 0)
    {
        printf("Create child process fail!\n");
    }
    else if(iRet == 0)
    {
        printf("child process id:%d ppid:%d\n", getpid(),
                getppid());
    }
    else
    {
        printf("parent process success,child id:%d\n", iRet);
    }

    return 0;
}
