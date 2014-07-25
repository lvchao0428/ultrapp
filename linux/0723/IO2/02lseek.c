
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    int fd = open("test.txt", O_RDONLY, 0666);
    if(fd == -1)
    {
        ERR_EXIT("open");
    }

    char buf[1024] = {0};

    off_t len = lseek(fd, 6, SEEK_CUR);
    printf("offset = %d\n", (int)len);
    
    memset(buf, 0, sizeof(buf));
    read(fd, buf, 5);
    printf("buf = %s\n", buf);

    len = lseek(fd, 0, SEEK_CUR);
    printf("offset = %d\n", (int)len);

    close(fd);


    return 0;
}
