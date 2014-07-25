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
        ERR_EXIT("open");

    int fd2 = open("test.txt", O_RDONLY, 0666);
    if(fd2 == -1)
        ERR_EXIT("OPEN");
    char buf[100] = {0};
    read(fd, buf, 5);
    printf("fd1, buf = %s\n", buf);

    char buf2[100] = {0};
    read(fd2, buf2, 6);
    printf("fd2, buf2 = %s\n", buf2);

    read(fd, buf, 10);
    printf("fd1, buf = %s\n", buf);

    read(fd2, buf2, 10);
    printf("fd2, buf2 = %s\n", buf2);




    return 0;
}
