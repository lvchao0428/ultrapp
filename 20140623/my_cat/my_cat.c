/*************************************************************************
	> File Name: my_cat.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sun 22 Jun 2014 10:19:05 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
	int fd_n, read_n;
	char s[1024];
	char fs[1024];
	FILE * fp;
	int file_n=1;
	if(argc == 1 )
	{
	//	printf("two few args !\n");
//		while(fflush(stdin),gets(s)!= NULL )
			gets(s);
			puts(s);
	}
	else
	{
		while(file_n <= argc)
		{

			fd_n = open(argv[file_n], O_RDONLY);
			file_n++;
	//		if(fd_n == -1)
	//		{
	//			perror("fail:");
	//			exit(-1);
	//		}
			while(memset(fs, 0, 1024),(read_n = read(fd_n , fs, 1024))>0)
			{
//				write(fd_n,buf,read_n)
				printf("%s", fs);
			}
			close(fd_n);
		}

	}

		
	return 0;
}

