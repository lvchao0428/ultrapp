
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"
#include <time.h>
void task_func(void *arg)
{
    int t = (int)arg;
    printf("pthread %x, inum=%d\n", (unsigned int)pthread_self(), t*t);
    sleep(1);
}


int main(int argc, const char *argv[])
{
    pool_t pool;
    pool_init(&pool, 10);
    pool_start(&pool);
    srand(time(NULL));

    while(1)
    {
        sleep(1);
        task_t task;
        task.thread_callback = task_func;
        task.arg_ = (void*)(rand()%10);
        pool_addtasktothepool(&pool, task);
    }


    pool_stop(&pool);
    pool_destroy(&pool);
    return 0;
}
