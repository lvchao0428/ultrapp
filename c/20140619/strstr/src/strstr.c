/*************************************************************************
	> File Name: strstr.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 18 Jun 2014 11:02:58 PM EDT
 ************************************************************************/

#include<stdio.h>

char * my_strstr(char *s1,char *s2)
{
	int i, j=0, flag = 0;
	char *c;
	for(i=0; s1[i]!= '\0'; ++i)
	{
		flag = 0;
		for(j=0; s2[j] != '\0'; ++j)
		{
			if(s1[i] == s2[j])
			{
				if(flag == 0)
					c = &s1[i];
				flag = 1;
			}
			else
			{
				flag = 0;
				c = NULL;
			}
		}
		if(flag == 1)
			return c;

	}
	return c;
}
