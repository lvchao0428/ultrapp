/*************************************************************************
	> File Name: my_lseek.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 23 Jun 2014 03:08:05 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct stu
{
	int no;
	char name[20];	
}stu, *pstu;

int main(int argc, char **argv)
{
	int fd_wrrd,read_n;
	char buf[1024];
	stu st;
	fd_wrrd = open("stu.txt", O_RDWR | O_CREAT);
	if(fd_wrrd == -1)
	{
		perror("fail:");
		exit(-1);
	}

	int i;
	for(i=0; i<5; ++i)
	{

	}
	while(fflush(stdin), (read_n = read(fd_wrrd, &st, sizeof(stu)))>0)
	{
		printf("no:%d, name:%s\n", st.no, st.name);
	}
	lseek(fd_wrrd, 3*sizeof(stu), SEEK_SET);
	lseek(fd_wrrd, -sizeof(stu), SEEK_CUR);
	stu sst = {100, "吕超"};
	write(fd_wrrd, &sst, sizeof(stu));
	lseek(fd_wrrd, 0, SEEK_SET);
	while(fflush(stdin), (read_n = read(fd_wrrd, &st, sizeof(stu)))>0)
	{
		printf("no:%d, name:%s\n", st.no, st.name);
	}
	return 0;
}
