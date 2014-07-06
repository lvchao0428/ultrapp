/*************************************************************************
	> File Name: main_pool.c
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Sat 05 Jul 2014 03:32:13 AM EDT
 ************************************************************************/

#include "pool.h"

int main(int argc,char *argv[])
{//exe ip port cnt
	if(argc != 4)
	{
		perror("usage:exe cnt!\n");
		exit(-1);
	}

	int chld_cnt = atoi(argv[1]);
	SA server_addr ;
	int fd_server, max_fd, index;
	fd_set read_set, ready_set ;
	pCHLD chlds = (pCHLD)calloc(chld_cnt, sizeof(pCHLD));
	max_fd = make_child(chlds, chld_cnt) ;
	bzero(&server_addr, sizeof(SA));
	fd_server = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd_server == -1)
	{
		perror("sock");
		exit(-1);
	}
	server_addr.sin_family = AF_INET ;
	server_addr.sin_port = htons(atoi(argv[2]));
	server_addr.sin_addr.s_addr = inet_addr(argv[1]);
	if(-1 == bind(fd_server, 
				(struct sockaddr*)&server_addr, sizeof(SA)))
	{
		perror("bind");
		close(fd_server);
		exit(-1);
	}
	max_fd = max_fd > fd_server ? max_fd : fd_server ;

	FD_ZERO(&read_set);
	FD_SET(fd_server, &read_set) ;
	for(index = 0; index < chld_cnt ; index ++)
	{
		FD_SET(chlds[index].s_read, &read_set);
		
	}
	struct timeval tm;
	while(1)
	{
		tm.tv_usec = 1000 ;
		tm.tv_sec = 0;
		ready_set = read_set ;
		select(max_fd + 1, &read_set, NULL,NULL,
				&tm);
		if(FD_ISSET(fd_server, &read_set))
		{
			char buf[1024] = "";
			SA from_addr ;
			int addrlen = sizeof(SA);
			bzero(&from_addr, sizeof(SA));
			recvfrom(fd_server, buf,1024, 0,
					(struct sockaddr*)&from_addr, &addrlen) ;

			for(index = 0; index < chld_cnt; index ++ )
			{
				if(chlds[index].s_flag == S_IDLE)
				{
					break;
				}
			}
			if(index == chld_cnt)
			{
			}
			else
			{
				chlds[index].s_flag = S_BUSY;
				chlds[index].s_cnt ++;
				FILE* fp = fdopen(chlds[index].s_write, "w");
				fprintf(fp, "%d %d %s", from_addr.sin_port,
						from_addr.sin_addr.s_addr, buf); //port ip request
				fflush(fp);
			}
		}
		for(index = 0; index < chld_cnt; index ++)
		{
			char ch ;
			if(FD_ISSET(chlds[index].s_read, &ready_set))
			{
				read((chlds[index].s_read), &ch, 1);
				chlds[index].s_flag = S_IDLE;
			}


		}
	}
	return 0 ;
}
