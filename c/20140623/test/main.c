/*************************************************************************
	> File Name: main.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 24 Jun 2014 03:14:07 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char s[100] = "china is a big country.";
	char ss[20][100];
	int i=0, j=0;

	while(s[i]!='\0')
	{
		sscanf(s+i,"%s", ss[j]);
		i += strlen(ss[j])+1;
		printf("%d\n", i);
		j++;
	}
	int k = 0;
	while(k<j)
	{
		printf("%s\n", ss[k]);
		k++;
	}
	return 0;
}
