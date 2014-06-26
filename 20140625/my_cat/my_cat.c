/*************************************************************************
	> File Name: my_cat.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 24 Jun 2014 11:19:47 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char buf[100];
	strcpy(buf, "cat");
	int i;
	for(i=1; i<argc; ++i)
	{
		strcat(buf, " ");
		strcat(buf, argv[i]);
	}

	system(buf);

	return 0;
}
