/*************************************************************************
	> File Name: my_cond.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 30 Jun 2014 10:29:43 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <time.h>
#include <string.h>
#define N 20


int queue[N];
int front , rear;
pthread_cond_t produce_cond, consume_cond;
pthread_mutex_t queue_mutex;
int left_cnt=20, product_cnt=0;

void* producer(void* arg);
void* consumer(void* arg);



int main(int argc, char *argv[])
{
	front = -1;
	rear = 0;
	srand(getpid());
//	left_cnt = 20;
//	product_cnt = 0;
	int pro_n = atoi(argv[1]), con_n = atoi(argv[2]);

	printf("pro_n:%d\n", pro_n);
	printf("con_n:%d\n", con_n);

	pthread_mutex_init(&queue_mutex, NULL);
	pthread_cond_init(&produce_cond, NULL);
	pthread_cond_init(&consume_cond, NULL);

	pthread_t tid1, tid2;
	while(pro_n>0 || con_n >0)
	{
		if(con_n > 0)
		{
		pthread_create(&tid2, NULL, consumer, NULL);
		}
		if(pro_n >0)
		{
		pthread_create(&tid1, NULL, producer, NULL);
		}
		pro_n--;
		con_n--;	
	}
	while(1);
	pthread_mutex_destroy(&queue_mutex);
	pthread_cond_destroy(&produce_cond);
	pthread_cond_destroy(&consume_cond);
}

void* producer(void* arg)
{
	pthread_detach(pthread_self());
	while(1)
	{
		pthread_mutex_lock(&queue_mutex);
		while(left_cnt == 0)
		{
			pthread_cond_wait(&produce_cond, &queue_mutex);			
		}

		product_cnt++;
		
		if(product_cnt == 1)
		{
			pthread_cond_broadcast(&consume_cond);
		}

		printf("produce in:%d\n", product_cnt);
		left_cnt--;	
		pthread_mutex_unlock(&queue_mutex);
		sleep(rand()%4+1);
	}
}

void* consumer(void* arg)
{
	pthread_detach(pthread_self());
	while(1)
	{
		pthread_mutex_lock(&queue_mutex);
		while(product_cnt == 0)
		{
			pthread_cond_wait(&consume_cond, &queue_mutex);
		}

		

		
		product_cnt--;
		if(product_cnt == 0)
		{
			pthread_cond_broadcast(&produce_cond);
		}



		printf("product out:%d\n", product_cnt);
		left_cnt++;
		
		
		pthread_mutex_unlock(&queue_mutex);


		sleep(rand()%4+1);
		

	

	}
}
