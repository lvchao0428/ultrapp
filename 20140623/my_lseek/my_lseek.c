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
	char buf[1024]	;
	stu st[5] = {
		{1,"jordan"}, 
		{2,"lisi"},
		{3,"wangwu"},
		{4,"zhaoliu"},
		{5, "houqi"}
	};

	fd_wrrd = open("stu.txt", O_RDWR | O_CREAT);
	if(fd_wrrd == -1)
	{
		perror("fail:");
		exit(-1);
	}

	int i;
	for(i=0; i<5; ++i)
	{

		//strcpy(buf, itoa(st[i].no));
		//strcat(buf, st[i]);
		//lseek()
		write(fd_wrrd, &st[i], sizeof(stu));
	}
	
	return 0;
}
