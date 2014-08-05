#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

void *thread_func(void *arg)
{
    pthread_detach(pthread_self());
    printf("hello\n");
    pthread_exit(NULL);
}

int main(int argc, const char *argv[])
{
    pthread_t tid;
    void *(*pf)(void*);
    pf = &thread_func;
    pthread_create(&tid, NULL, pf, NULL);
    while(1);
    pause();
        
    return 0;
}
