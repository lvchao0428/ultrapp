

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, const char *argv[])
{
    char szBuf[32] = {'\0'};

    int iFile = open("./a.txt", O_RDONLY);

    if(fork() > 0)
    {
        close(iFile);
        return 0;
    }

    sleep(0);
    if(read(iFile, szBuf, sizeof(szBuf)-1) < 1)
    {
        perror("read fail");
    }
    else
    {
        printf("string :%s\n", szBuf);
    }
    close(iFile);

    return 0;
}
