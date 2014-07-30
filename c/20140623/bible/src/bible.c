/************************************************************************
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
#include <ctype.h>

pTXT init_txt(char * file_name)
{
	int fd_rd, read_n, i, j=0, k=0;
	pTXT pt = (pTXT)malloc(sizeof(TXT));
	char buf[1024];
	i=0;
//	printf("fuck");
	pt->des_word = (pTXT_WORD)calloc(1, sizeof(TXT_WORD)*MAX_WORD_COUNT);

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
		
	//	printf("fuck");
		
		while(buf[i]!= '\0')
		{
			if(is_character(buf[i]))
			{
				pt->src_txt[j][k] = buf[i];
				pt->char_num++;	
				if(isupper(buf[i]))
					pt->des_txt[j][k] = buf[i]+32;
				else
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
				//去空格
				despace(pt->des_txt[j]);
			//	printf("%s jj\n", pt->des_txt[j])	;
				
				char word[100];
				int word_pos = 0;
				int index;
				
				while(memset(word, 0, 100), 
						sscanf(pt->des_txt[j]+word_pos , "%s", word )==1)
				{
					printf("word:%s\n", word);
					word_pos += strlen(word)+1;
					index = 0;
					for(;index < pt->word_e_num; ++index)
					{
						if(strcmp(word, pt->des_word[index].word) == 0)
						{
						
							pt->des_word[index].count++;
							break;
						}
					}	

					if(index >= pt->word_e_num)
					{
						pt->word_e_num++;
						strcpy( pt->des_word[index].word, word);
						pt->des_word[index].count++;
					}
		//			memset(word, 0, 100);
				}
				
				
				pt->line_num++;
				k=0;
				j++;
				i++;
				continue;

			}
			
			k++;
			i++;
		}
		
	}
//	printf("over");
	return pt;
}

void despace(char *buf)
{
	char ss[1024];
//	strcpy(ss, buf);
	
	int i=0, j=0;
	while(buf[i]!='\0')
	{
		while(buf[i] == ' ')
			i++;
		if(buf[i] != ' ')
		{		
			ss[j] = buf[i];
			j++;
			i++;
			if(buf[i]== ' ')
			{
				ss[j] = ' ';
				j++;
				i++;
			}
		}
		
	}
	strcpy(buf, ss);
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
	if((ch>='a'&&ch<='z' )|| (ch >='A'&&ch<='Z'))
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

void fill_the_word(pTXT pt, char *buf)
{
	char *ss = (char*)malloc(sizeof(char)*30);
	int i=0;
	int j;
	while(buf[i] != '\0')
	{
		memset(ss, 1, 30);
		sscanf(buf+i, "%s", ss);
		i += strlen(ss)+1;
	//	printf("%s", ss);
//		strcpy(, ss);
//		j=0;

		insert_word(pt, ss);
	}
}

void insert_word(pTXT pt, char *word)
{
	int i;
	if(pt->word_e_num == 0)
	{
		strcpy(pt->des_word[0].word, word);
	}
	for(i=0; i<pt->word_e_num; ++i)
	{
		
		if(strcmp(pt->des_word[i].word, word)==0)
		{
			pt->des_word[i].count++;
		}
	}
	if(i==pt->word_e_num)
	{
		strcpy(pt->des_word[i].word, word);
	}
	pt->word_e_num++;
}

void str_next(char* par, int *next)
{
	
}

void str_search(char *src, char *par, pTXT pt)
{
	
}
