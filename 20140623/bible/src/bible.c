/*************************************************************************
	> File Name: bible.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Mon 23 Jun 2014 05:08:49 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "bible.h"

pTXT init_txt(char * file_name)
{
	int fd_rd, read_n, i, j=0, k=0;
	pTXT pt = (pTXT)malloc(sizeof(TXT));
	char buf[1024];
	i=0;
	while(i<MAX_TXT_LINE)
	{
//		printf("init max_txt_line");
		pt->src_txt[i] = (char*)calloc(1, 1024);
		pt->des_txt[i] = (char*)calloc(1, 1024);
		i++;
	}
	fd_rd = open(file_name, O_RDONLY);
	if(fd_rd == -1)
	{
		perror("cannot open the file");
		exit(-1);
	}
	pt->word_e_num=0;
	pt->word_num = 0;
	pt->line_num = 0;
	pt->char_num = 0;
	while(memset(buf, 0, 1024), (read_n = read(fd_rd, buf, 1024))>0)
	{
		i=0;
		
		
		while(buf[i]!= '\0')
		{
			
			if(is_character(buf[i]))
			{
				pt->src_txt[j][k] = buf[i];
				pt->char_num++;	
				pt->des_txt[j][k] = buf[i];
			}
			else if(buf[i] != '\n')
			{
				pt->src_txt[j][k] = buf[i];
				pt->des_txt[j][k] = ' ';	
			}
			if(buf[i] == '\n')
			{
				pt->src_txt[j][k] = '\0';
				pt->des_txt[j][k] = '\0';
				pt->line_num++;
				k=0;
				j++;
			}
			else
				k++;
			i++;
		}
		
	}
	printf("over");
	return pt;
}



void depunct(char *fp, char *ss)
{
	int fd_rd, fd_wr,read_n , i, j;
	char buf[1024], buf_1[1024];
	fd_rd = open(fp, O_RDONLY);
	if(fd_rd == -1)
	{
		perror("cannot open the bible.");
		exit(-1);
	}
//	fd_wr = open(fp, O_WRONLY | O_CREAT);
	if(fd_wr == -1)
	{
		perror("fail:");
		exit(-1);
	}
	j =0 ;
	while(memset(buf, 0, 1024), 
			memset(buf_1,0,1024), 
			(read_n = read(fd_rd, buf, 1024)))
	{
		i=0;
		while(buf[i]!='\0')
		{
			if(is_character(buf[i]))
				ss[j++] = buf[i++];
			else 
				ss[j++] = '\0';
		}
	}
}

int is_character(char ch)
{
	if((ch>='a'||ch<='z' )|| (ch >='A'&&ch<='Z'))
		return 1;
	else
		return 0;
}

int is_space(char ch)
{
	if(ch == ' ')	
		return 1;
	else
		return 0;
}


