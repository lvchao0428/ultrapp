/*************************************************************************
	> File Name: my_sh.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 07:38:51 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "my_sh.h"
#include <string.h>
#include <unistd.h>
#include <malloc.h>

#define N 32 

int main(int argc, char *argv[])
{
	char hostname[100];
//	printf("user_name:%s\n", get_usr_name());
	get_hostname(hostname);

//	printf("host_name:%s\n", hostname);
	//printf("%s\n", prompt);
	char prompt[200];
	char line[100];
//	char dir[100];
//	getcwd(dir, 90);
//	printf("%s", dir);
	strcpy(prompt, "[");
	strcat(prompt, get_usr_name());
	strcat(prompt, "@");
	strcat(prompt, hostname);
//	strcat(prompt, " ");

//	strcat(prompt, dir);
//	strcat(prompt, "]");
	while(1)
	{
	//	system("clear");
		printf("%s\n", prompt);
		while(fgets(line, 100, stdin), line[0]!='\n')
		{
	//		printf("%s\n", line);
			char *arglist[N];//(char**)malloc(sizeof(char*)*N);
			int i=0;
			while(i<N)
			{
				
				arglist[i] = (char*)calloc(100, sizeof(char));
				i++;
			}
	//		printf("begin process:\n");
			process(line, arglist);
			outputarg(arglist)	;
	//		printf("process over.");
			int iret;	
			if(fork() > 0)
			{			
				wait(NULL);
		//		exit(-1);
			}
			else
			{
				iret = execvp(arglist[0], arglist);
				
				if(iret == -1)				
				{
					perror("error");
					exit(0);
				}

				//exit(-1);
			}
		}
		//printf wrong info.

	}

}





