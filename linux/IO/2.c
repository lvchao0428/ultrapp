
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define ERR_EXIT(m)\
    do\
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0);

int main(void)
{
    int fd;
    fd = open("test.txt", O_RDONLY);
    
    if(fd == -1)
    {
        fprintf(stderr, "open error with errno=%d%s\n", errno,
                strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("open succ\n");

    return 0;
}
