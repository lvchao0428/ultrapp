/*************************************************************************
	> File Name: rm.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 30 Jun 2014 05:29:51 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

int read_cnt = 0;
int write_flag = 1;
pthread_mutex_t read_m, access_m, write_m;
int cnt = 3;

void* read_rt(void *arg);

void* write_rt(void* arg);


int main()
{

pthread_t read_tid, write_tid;
	pthread_mutex_init(&read_m, NULL);
	pthread_mutex_init(&access_m, NULL);
	pthread_mutex_init(&write_m, NULL);
	int n;
	srand(getpid());
	while(1)
	{
		if(rand()%2 == 0)
			pthread_create(&read_tid, NULL, read_rt, NULL);
		else
			pthread_create(&write_tid, NULL, write_rt, NULL);
		sleep(1);
	}
	pthread_mutex_destroy(&read_m);
	pthread_mutex_destroy(&write_m);
	pthread_mutex_destroy(&access_m);

	return 0;

}

void* read_rt(void* arg)
{
	pthread_detach(pthread_self());
	pthread_mutex_lock(&read_m);
	if(read_cnt == 0)
	{
		pthread_mutex_lock(&access_m);
	}
	read_cnt++;
	pthread_mutex_unlock(&read_m);
	//读者读
	sleep(1);
	printf("read the cnt:%d\n", cnt);
	//读完毕
	pthread_mutex_lock(&read_m);
	read_cnt--;
	if(read_cnt == 0)
	{
		pthread_mutex_unlock(&access_m);
	}
	pthread_mutex_unlock(&read_m);

	
	
}

void* write_rt(void *arg)
{
	pthread_detach(pthread_self());

	
	pthread_mutex_lock(&access_m);
	


	printf("write before cnt:%d\n", cnt);
	sleep(1);
	++cnt;
	printf("write after cnt:%d\n", cnt);


	pthread_mutex_unlock(&access_m);





}
