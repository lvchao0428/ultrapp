
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    execl("./add.exe", "add.exe", "3", "4", NULL);

    return 0;
}
