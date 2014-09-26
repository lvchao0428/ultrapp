#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

pthread_once_t once_control = PTHREAD_ONCE_INIT;

void test_once()
{
    printf("test....\n");
}

void *thread_func(void *arg)
{
    pthread_once(&once_control, test_once);

    printf("in thread %lu\n", (unsigned long)pthread_self());

    return NULL;
}

int main(int argc, const char *argv[])
{
    pthread_t threads[10];

    int i;
    for (i = 0; i != 10; i++) 
    {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }


    for (i = 0; i < 10; i++) 
    {
        pthread_join(threads[i], NULL);
    }
        
        
    
    
    return 0;
}
