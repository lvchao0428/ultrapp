/*************************************************************************
	> File Name: my_gethost.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Wed 02 Jul 2014 02:52:59 AM EDT
 ************************************************************************/

#include<stdio.h>
#include <netdb.h>
int main(int argc, char *argv[])
{
	struct hostent* my_ent;
	struct hostent* my_ent1;
	if(argc == 1)
	{
		char buf[128] = "";
		gethostname(buf, 128);
		printf("hostname:%s\n", buf);
		my_ent = gethostbyname(buf);
		my_ent1 = gethostbyaddr((char*)my_ent->h_addr_list[0], 4, AF_INET);
		
	}
	else
	{
		my_ent = gethostbyname(argv[1]);
	}
	printf("host_name:%s\n", my_ent1->h_name);
	printf("addr_type:%d\n", my_ent1->h_addrtype);
	printf("addr_len: %d\n", my_ent1->h_length);
	printf("addr_list:\n");
	char **p = my_ent1->h_addr_list ;
	for(;*p != NULL; ++p)
	{
		
		printf("%x\n", *(int*)*p);
	}
	
	return 0;
}
