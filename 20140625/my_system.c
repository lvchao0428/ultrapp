/*************************************************************************
	> File Name: my_system.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 24 Jun 2014 11:00:54 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char buf[100];
	int i;
	sprintf(buf, "./main");
	for(i=1; i<argc; ++i)
	{
		strcat(buf," ");
		strcat(buf, argv[i]);
	}
	int j;
	j = system(buf);
//	printf("%d\n", j);
	system("ps -aux");
	return 0;
}
