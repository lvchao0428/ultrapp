
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    printf("pid:%d      ppid:%d\n", getpid(), getppid());

    return 0;
}
