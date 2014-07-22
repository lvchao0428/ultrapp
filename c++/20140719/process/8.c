
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 100

int main(int argc, const char *argv[])
{
    FILE *read_fp;
    char buffer[BUFF_SIZE + 1];
    int chars_read;

    memset(buffer, '\0', sizeof(buffer));

    read_fp = popen("ps -ax", "r");
    if(read_fp != NULL)
    {
        chars_read = fread(buffer, sizeof(char), BUFF_SIZE,
                read_fp);
        while(chars_read > 0)
        {
            buffer[chars_read - 1] = '\0';
            printf("reading:-\n%s\n", buffer);
            chars_read = fread(buffer, sizeof(char), BUFF_SIZE, read_fp);
        }
        pclose(read_fp);
        exit(EXIT_SUCCESS);
    }
    exit(EXIT_SUCCESS);

    return 0;
}
