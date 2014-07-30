/*************************************************************************
	> File Name: my_child.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 03 Jul 2014 07:37:54 AM EDT
 ************************************************************************/

#include "my_child.h"

void make_chld(pCHLD arr, int cnt)
{
	int index;
	for(index = 0; index < cnt; ++index)
	{
		pid_t pid;
		int fds1[2], fds2[2];
		//fds 1 pr fds2 pw
		pipe(fds1);
		pipe(fds2);
		pid = fork();
		if(pid == 0)
		{
			close(fds1[0]);
			close(fds2[1]);
			dup2(fds1[1], 1);
			dup2(fds2[0], 0);
			close(fds1[1]);
			close(fds2[0]);
			child_main() ;
		}
		else
		{
			close(fds1[1]);
			close(fds2[0]);
			arr[index].s_pid = pid;
			arr[index].s_status = 
				S_IDLE;
			arr[index].s_read = 
				fds1[0];
			arr[index].s_write =
				fds2[1];
			arr[index].s_cnt = 0;
		}
	}
}

void child_main()
{
	int fd_client;
	int over = 1;
	while(scanf("%d", &fd_client)==1)
	{
		handle_request(fd_client);
		printf("%d\n",over);
		
	}
}
