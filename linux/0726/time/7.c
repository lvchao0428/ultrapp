#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

int main(int argc, char *argv[])
{
    int opt;
    while(1)
    {
        opt = getopt(argc, argv, "nt:");
        if(opt == '?')
            exit(EXIT_FAILURE);
        if(opt == -1)
            break;
        switch(opt)
        {
            case 'n':
                printf("-n\n");
                break;
            case 't':
                printf("-t%d\n", atoi(optarg));
                break;
        }
    }

    return 0;
}
