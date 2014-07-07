/*************************************************************************
	> File Name: my_hton.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Tue 01 Jul 2014 09:42:04 PM EDT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define my_hton(ip)	\
	((ip & 0xff) << 24) |\
((ip & (0xff << 8)) << 8)|\
((ip & (0xff << 16)) >> 8)|\
((ip & (0xff << 24)) >> 24)
int main(int argc, char *argv[])
{
	char cip[100];
	int hip, nip;
	strcpy(cip, argv[1]);
	int a[4];
	sscanf(argv[1], "%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
	hip = a[3] << 24 |   a[2] << 16  |   a[1] << 8  | a[0];
	nip = my_hton(hip);
	printf("host: %32x\n", hip);
	printf("net: %32x\n", nip);
	return 0;
}
