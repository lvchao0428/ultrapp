/*************************************************************************
	> File Name: my_fdopen.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 09:15:01 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd;
	fd = open("a.out", OWRONLY|O_CREAT);
	
	FILE * fp;
	fp = fdopen(fd, "w");

	fprintf(fp, "%s %d %c\n","hello",13,97);
	
	fclose(fp);

	close(fd);
}
