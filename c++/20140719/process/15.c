
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, const char *argv[])
{
    printf("using exit...\n");
    printf("this is the content in buffer");

    _exit(0);

    return 0;
}
