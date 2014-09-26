
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    pid_t pid = fork();

    if(pid == 0)
    {
        while(1);
    }
    else
    {
        exit(10);
    }

    return 0;
}
