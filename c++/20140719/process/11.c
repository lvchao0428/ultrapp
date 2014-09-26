
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    pid_t pid = fork();
    if(pid == 0)
    {
        exit(10);
    }
    else
    {
        wait(NULL);
        sleep(10);
    }

    return 0;
}

