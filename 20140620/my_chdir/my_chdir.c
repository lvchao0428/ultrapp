/*************************************************************************
	> File Name: my_chdir.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 10:09:14 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int x;
	x = chdir(argv[1]);
	if(x)
	{
		perror("fail to cd:");
	}
	printf("cd:%s.", getcwd(NULL,0));
	getchar();

	return 0;
}
