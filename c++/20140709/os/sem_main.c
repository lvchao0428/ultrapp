/*************************************************************************
	> File Name: sem_main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 12:32:01 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include "queue.h"

#define ERR_EXIT(m) \
    do { \
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

#define BUFFERSIZE 5

sem_t full;
sem_t empty;
pthread_mutex_t mutex;

QUEUE Q;

void *producer(void *arg)
{
    while(1)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        int num = rand()%10;
        queue_push(&Q, num);
        printf("push a num %d\n", num);

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(rand()%5 + 1);
    }
}

void *consumer(void *arg)
{
    while(1)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int num = queue_top(&Q);
        printf("pop a num %d\n", num);
        queue_top(&Q);

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        sleep(3);
    }
}

int main(int argc, const char *argv[])
{
    srand(time(NULL));
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFERSIZE);
    pthread_mutex_init(&mutex, NULL);
    queue_init(&Q);
    
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    queue_destroy(&Q);
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
