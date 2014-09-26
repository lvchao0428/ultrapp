/*************************************************************************
	> File Name: my_cwd.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 19 Jun 2014 09:56:15 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	printf("%s\n", get_current_dir_name(NULL,0));

	return 0;
}
