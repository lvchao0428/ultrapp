/*************************************************************************
	> File Name: inet_ntoa.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 02 Jul 2014 02:01:26 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int a[4];
	int nip;
	char ss[100];
	printf("nip:");
	scanf("%x", &nip);
	a[0] = (nip & ((unsigned int)0xff << 24 ) ) >> 24;
	a[1] = (nip & (0xff << 16 ) ) >> 16;
	a[2] = (nip & (0xff << 8) ) >> 8;
	a[3] = (nip & (0xff));
	sprintf(ss, "%d.%d.%d.%d", a[0], a[1], a[2], a[3]);

	printf("net ip: %s\n", ss);

	return 0;
		
	
}
