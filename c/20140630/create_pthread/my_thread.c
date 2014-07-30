/*************************************************************************
	> File Name: my_thread.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 30 Jun 2014 02:29:54 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <malloc.h>
#define N 100000000
void* my_hander(void* arg);

int main(int argc, char *argv[])
{
	pthread_t tid;
	int thread_ret;
	char *ss;
	int i;
	int *a = (int *)calloc(N, sizeof(int));
	printf("main: hellow rold\n");
	pthread_create(&tid, NULL, my_hander, (void*)a);
	printf("begin join\n");
	
    pthread_join(tid, (void*)&ss);
	printf("after join\n");
	printf("thread_ret:%s\n", ss);
	sleep(10);
	return 0;
}

void *my_hander(void* arg)
{
	int *a = (int*)arg;
	char *s = "how are you";
	srand(time(NULL));
	int sum = 0;
	int i;
//	strcpy(s, "how are you\n");
	for(i=0; i<N; i++)
	{
		a[i] = rand()%100;
		sum += a[i];
	}
	printf("sum of 1 to %d is:%d\n", N,sum)	;
//	exit(1);
//	return (void*)s;
	pthread_exit((void*)s);
}
