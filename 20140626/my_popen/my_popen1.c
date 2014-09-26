/*************************************************************************
	> File Name: my_popen1.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 25 Jun 2014 09:42:55 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	char buf[1024];
	fp = popen("./mr1", "w");
		
	while(memset(buf, 0, 1024), fgets(buf, 1024, stdin)!= NULL)
	{
		if(buf[0] != '\n')	
		{
		//	fprintf(fp, "%s", buf);
			fwrite(buf, 1, 1024, fp);
			fflush(fp);
		}
	}


	pclose(fp);
	

}
