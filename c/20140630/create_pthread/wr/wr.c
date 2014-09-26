/*************************************************************************
	> File Name: wr.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 30 Jun 2014 08:38:37 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int read_cnt = 0, write_cnt = 0;
int write_flag = 1;
pthread_mutex_t read_m, write_m, access_m;

int cnt = 4;

void *write_handler(void * arg);
void *read_handler(void* arg);

int main()
{
	pthread_t read_tid, write_tid;
	srand(getpid());
	pthread_mutex_init(&read_m, NULL);
	pthread_mutex_init(&write_m, NULL);
	pthread_mutex_init(&access_m, NULL);

	while(1)
	{
		if(rand()%2 == 0)
		{
			pthread_create(&read_tid, NULL, write_handler, NULL);
		}
		else
		{
			pthread_create(&write_tid, NULL, read_handler, NULL);
		}
		sleep(1);
	}

	pthread_mutex_destroy(&read_m);
	pthread_mutex_destroy(&write_m);
	pthread_mutex_destroy(&access_m);

	return 0;
	
}

void* read_handler(void * arg)
{
	pthread_detach(pthread_self());
	while(write_cnt > 0)	
	{
	}
	
	pthread_mutex_lock(&read_m);
	if(read_cnt == 0)
		pthread_mutex_lock(&access_m);
	read_cnt++;
	pthread_mutex_unlock(&read_m);

	printf("read cnt: %d\n", cnt);
	sleep(1);
	pthread_mutex_lock(&read_m);
	read_cnt--;
	if(read_cnt == 0)
		pthread_mutex_unlock(&access_m);
	pthread_mutex_unlock(&read_m);

}

void *write_handler(void* arg)
{
	pthread_detach(pthread_self());
	pthread_mutex_lock(&write_m);
	write_cnt++;
	pthread_mutex_unlock(&write_m);
	pthread_mutex_lock(&access_m);
	sleep(1);
//	sleep(3);
	printf("before write cnt:%d\n", cnt);
	cnt++;
	printf("after write cnt:%d\n", cnt);
		pthread_mutex_unlock(&access_m);
	pthread_mutex_lock(&write_m);
	write_cnt--;
	pthread_mutex_unlock(&write_m);
}
