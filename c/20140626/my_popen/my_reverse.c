/*************************************************************************
	> File Name: my_reverse.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 09:51:52 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
void reverse_str(char *str);
int main()
{
	char buf[1024];

	while(memset(buf, 0, 1024), fgets(buf, 1024, stdin)!=NULL)
	{
		if(buf[0] != '\n')
		{
			buf[strlen(buf)-1] = '\0';
			reverse_str(buf);
			printf("reverse: \n%s\n", buf);
		}
	}

}

void reverse_str( char *str)
{
	char c;
	int n = strlen(str);
	int i;
	for(i=0; i<n/2; ++i)
	{
		c = str[i];
		str[i] = str[n-i-1];
		str[n-i-1] = c;
	}
}
