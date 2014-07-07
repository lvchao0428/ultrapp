/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sun 06 Jul 2014 10:20:30 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
void dealcd(char *buf);
int main(int argc, char *argv[])
{
	char buf[1024];
	char comd[1024];
	int x;
	
	while(1)
	{
		printf("%s\n", getcwd(NULL, 0));
	fgets(buf, 1024, stdin);
	dealcd(buf);
	buf[strlen(buf)-1]= '\0';
	puts(buf);
	chdir(buf);
	
	}
	return 0;
}

void dealcd(char *buf)
{
	int i, j;
	for(i=0, j=3; buf[j] != '\0'; ++j, ++i)
	{
		buf[i] = buf[j];
	}
	buf[i] = '\0';
}
