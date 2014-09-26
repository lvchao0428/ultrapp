/*************************************************************************
	> File Name: my_cond.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 30 Jun 2014 10:29:43 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <time.h>

#define N 20


int queue[N];
int front , rear;
pthread_cond_t produce_cond, consume_cond;
pthread_mutex_t queue_mutex, produce_mutex, left_mutex;
int left_cnt, product_cnt;

void* producer(void* arg);
void* consumer(void* arg);



int main()
{
	front = -1;
	rear = 0;
	srand(getpid());
	left_cnt = 20;
	product_cnt = 0;

	pthread_mutex_init(&queue_mutex, NULL);
	pthread_mutex_init(&produce_mutex, NULL);
	pthread_mutex_init(&left_mutex, NULL);
	pthread_cond_init(&produce_cond, NULL);
	pthread_cond_init(&consume_cond, NULL);

	pthread_t tid1, tid2, tid3;
	pthread_create(&tid1, NULL, producer, NULL);
	pthread_create(&tid2, NULL, consumer, NULL);
	pthread_create(&tid3, NULL, consumer, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);

	pthread_mutex_destroy(&queue_mutex);
	pthread_mutex_destroy(&left_mutex);
	pthread_mutex_destroy(&produce_mutex);
	pthread_cond_destroy(&produce_cond);
	pthread_cond_destroy(&consume_cond);
}

void* producer(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&left_mutex);
		if(left_cnt == 0)
		{
			pthread_cond_wait(&produce_cond, &left_mutex);			
		}

		pthread_mutex_unlock(&left_mutex);
		pthread_mutex_lock(&queue_mutex);
		pthread_mutex_lock(&produce_mutex);
		product_cnt++;
		
		printf("produce in:%d\n", product_cnt);
		if(product_cnt == 1)
		{
			pthread_cond_signal(&consume_cond);
		}

		
		pthread_mutex_unlock(&produce_mutex);

		pthread_mutex_lock(&left_mutex);
		left_cnt--;
		pthread_mutex_unlock(&left_mutex);

		

		pthread_mutex_unlock(&queue_mutex);
		sleep(rand()%4+1);
	}
}

void* consumer(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&produce_mutex);
		if(product_cnt == 0)
		{
			pthread_cond_wait(&consume_cond, &produce_mutex);
		}

		pthread_mutex_unlock(&produce_mutex);
		pthread_mutex_lock(&queue_mutex);
		

		pthread_mutex_lock(&left_mutex);
		left_cnt++;
		
		if(left_cnt >= 1)
		{
			pthread_cond_signal(&produce_cond);
		}

		pthread_mutex_unlock(&left_mutex);


		pthread_mutex_lock(&produce_mutex);
		product_cnt--;
		printf("product out:%d\n", product_cnt);

		pthread_mutex_unlock(&produce_mutex);

		pthread_mutex_unlock(&queue_mutex);


		sleep(rand()%4+1);
		

	

	}
}
