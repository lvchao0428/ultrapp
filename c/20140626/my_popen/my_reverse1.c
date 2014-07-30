/*************************************************************************
	> File Name: my_reverse1.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 10:20:34 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void trim_space(char *line)
{
	int i=0, j=0;
	while(line[j] != '\0')
	{
		if(line[j] != ' ') 
		{
			line[i++] = line[j];
		}
		else
		{
			if(line[i-1] != ' ')
			{
				line[i++] = ' ';
			}
		}
		j++;
	}
	while(line[i] == ' ')
	{
		i--;
	}
	line[++i] = '\0';
}

int split_word(char* line, char word[][100])
{
	int word_len=0;
	int i=0;
	while(memset(word[i], 0, 90),sscanf(line+word_len, "%s", word[i])==1)
	{
		printf("wordlen:%d\n", word_len);
		word_len += strlen(word[i])+1;
		i++;
	}
	return i;
}

void reverse_word(char word[][100], int n)
{
	char temp[100];
	
	int i=0;
	for(i=0; i<n/2; ++i)
	{
		strcpy(temp, word[i]);
		strcpy(word[i], word[n-i-1]);
		strcpy(word[n-i-1], temp);
	}
}

int main()
{
	char buf[1024];
	printf("enter string:\n");
	fgets(buf, 100, stdin);
//	puts(buf);
	char word[100][100];
	int n;
	trim_space(buf);
	n = split_word(buf, word);
	
	int i;
	for(i=0; i<n; ++i)
	{
		printf("%s\n", word[i]);
	}
	reverse_word(word, n);
	printf("after reverse:\n");

	for(i=0; i<n; ++i)
	{
		printf("%s\n", word[i]);
	}
	return 0;
}
