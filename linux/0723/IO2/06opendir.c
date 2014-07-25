
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, const char *argv[])
{
    DIR *dir = opendir(".");
    if(dir == NULL)
    {
        ERR_EXIT("opendir");
    }


    struct dirent *de;

    while((de = readdir(dir)) != NULL)
    {
        printf("%s\n", de->d_name);


    }

    closedir(dir);

    return 0;
}
