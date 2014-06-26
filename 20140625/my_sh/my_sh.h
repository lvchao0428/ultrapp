/*************************************************************************
	> File Name: my_sh.h
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 07:46:39 AM EDT
 ************************************************************************/

#ifndef _MY_SH_H_
#define _MY_SH_H_
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>

char* get_usr_name()
{
	uid_t uid = getuid();
	struct passwd* pwd = getpwuid(uid);

	return pwd->pw_name;
}


void get_hostname(char *hname)
{
	gethostname(hname, sizeof(hname)*20);
}

void get_dir(char *dir)
{
	char ss[100];
	getcwd(ss, 100);
	int i;
	while(ss[i]!= '\0')
	{
		i++;
	}
	while(ss[i] != '/')i--;
	i++;
	strcpy(dir, &ss[i]);
}

void process(char *line, char * arglist[32])
{
	int i=0, j=-1;
	int n = strlen(line);
	
	while(line[i] != '\0')
	{
		if(line[i] != ' ')
		{
			line[++j] = line[i];	
		}
		else
		{
			if(j!= -1 && line[j] != ' ')
				line[++j] = ' ';
		}
		i++;
	}
	while(j>=0)
	{
		if(line[j] != ' ')
		{
			break;
		}
		j--;
	}
	line[++j] = '\0';

//	printf("despace complete.\n");
	int len = 0;
	int z=0;
	while(sscanf(line+len,"%s", arglist[z])==1)
	{
//		printf("line+len:%s\n", line+len);
//		printf("len:%d\n", len);
	//	printf("arg[%d]%s\n",z, arglist[z] );
		len = len + strlen(arglist[z])+1;
		z++;
	}
	arglist[z] =  NULL;
//	printf("drag word complte.");

}


void outputarg(char *arg[10])
{
	int i=0;
//	printf("arg..\n");
	for(i=0; arg[i] != '\0'; ++i)
	{
//		printf("%s\n", arg[i]);
		if(arg[i][0] == '\0')
			break;
	}
}


#endif
