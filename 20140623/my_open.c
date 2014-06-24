


sdf
*******************************************************************
	> File Name: my_open.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sun 22 Jun 2014 09:42:33 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fd;
	if(argc != 2)
	{
		printf("two few args !\n");
	}
	fd = open(argv[1], O_WRONLY | O_CREAT,0666);
	if(fd == -1)
	{
		perror("fail:");
		exit(-1);
	}
	printf("fd: %d \n", fd);



}
