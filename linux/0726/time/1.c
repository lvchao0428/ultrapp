#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    time_t tt;
    char buf[1024];
    time(&tt);
    printf("%s buf:%s\n", ctime_r(&tt, buf), buf);
    sleep(2);
    printf("%s buf:%s\n", ctime_r(&tt, buf), buf);
    sleep(2);

    return 0;
}

