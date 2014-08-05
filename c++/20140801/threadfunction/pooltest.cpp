#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "def.h"

void task_func(void *arg)
{
    int t = (int)arg;
    printf("%d\n", t++);
}

int main(int argc, const char *argv[])
{
    pool_t pool(4);
    pool.thread_pool_start();

    srand(time(NULL));

    while(1)
    {
        sleep(1);
        task_t tsk;
        tsk.thread_func_ = task_func;
        tsk.arg_ = (void*)(rand() %100);
        pool.thread_pool_add_task_to_queue(tsk);

    }

    pool.thread_pool_stop();


    return 0;
}
