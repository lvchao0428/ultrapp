/*************************************************************************
	> File Name: my_thread_mutex.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 30 Jun 2014 04:50:57 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int cnt=0;
pthread_mutex_t my_mutex;

void *my_handler(void * argv);

int main(int argc, char *argv[])
{
	pthread_t tid1, tid2;
	pthread_mutex_init(&my_mutex, NULL);
	pthread_create(&tid1, NULL, my_handler, NULL);
	pthread_create(&tid2, NULL, my_handler, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&my_mutex);
	printf("cnt:%d\n", cnt);

	return 0;
}

void *my_handler(void * argv)
{
	int i;
	for(i=0; i<10000; ++i)
	{
		pthread_mutex_lock(&my_mutex);
		cnt++;
		pthread_mutex_unlock(&my_mutex);
	}
}
