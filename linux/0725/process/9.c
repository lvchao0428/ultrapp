
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int my_system(const char *command)
{
    pid_t pid;
    if(command == NULL)
        return 1;
    int status;
    
    if((pid = fork()) < 0)
        ERR_EXIT("FORK");
    else if(pid == 0)
    {
        execl("/bin/sh", "bash", "-c", command, NULL);
        exit(EXIT_FAILURE);
    }
    else
    {
        while(waitpid(pid, &status, 0) < 0)
        {
            if(errno == EINTR)
                continue;
            status = -1;
            break;
        }
    }
    return status;
}

int main(int argc, const char *argv[])
{
    
    printf("enter main....\n");

    my_system("ls");

    printf("leave main...\n");
    return 0;
}
