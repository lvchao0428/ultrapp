/*************************************************************************
	> File Name: server.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Thu 03 Jul 2014 10:02:48 AM CST
 ************************************************************************/
#include "socket.h"
#include <signal.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>

#include <unistd.h>
void send_dir(int fd_server);
void trim_space(char *buf);
void recv_msg(int fd_client);
void recv_command(int fd_client, char *comd);
void send_path(int fd_client, char *path);
void dealcd(char *buf);

void sig_handle(int num)
{
	while(waitpid(-1, NULL, WNOHANG) > 0) ;
}
int main(int argc , char* argv[])//exe ip port
{
	signal(13,SIG_IGN);
	signal(17,sig_handle);
	if(argc != 3)
	{
		printf("usge : exe ip port");
		exit(-1);
	}
	int fd_server ,fd_client;
	struct sockaddr_in client_addr ;
	int addrlen = sizeof(client_addr);
	fd_server = listenfd_init(argv[1],argv[2]);
	while( (fd_client = accept(fd_server,(struct sockaddr*)&client_addr,&addrlen) ) > 0 )
	{
		if(fd_client == -1)
		{
			if(errno == EINTR)
			{
				continue ;
			}
		}
		printf("a client connect :%s:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
		if(fork() == 0)
		{
			close(fd_server);
			char comd[1024];
			//circle recv msg
			while(1)
			{
				fflush(stdout);
				char sign[32];
				bzero(comd, 1024);
				recv_command(fd_client,comd);
				
				printf("comd:%s\n", comd);
				if(strncmp(comd, "ls", 2) == 0)
				{
					send_dir(fd_client);
				}
				else if(strncmp(comd, "download", 8) == 0)
				{
					ul_file(fd_client);
				}
				else if(strncmp(comd, "cd", 2) == 0)	
				{
					send_path(fd_client, comd);		
				}
				else if(strncmp(comd, "rm", 2) == 0)
				{
					system(comd);
				}
				else if(strncmp(comd, "upload", 6) == 0)
				{
					dl_file(fd_client);
				}
				else if(strncmp(comd, "cl", 2) == 0)
				{
					system("clear");
				}

			}
			exit(0);
		}
	}

}

void send_dir(int fd_client)
{
	MSG msgdir;

	DIR *pDir ;
	pDir = opendir(".");
	
	struct dirent* myent ;
	char dir[32];
	mode_t md;
	struct stat mystat;
	while((myent = readdir(pDir)) != NULL)
	{
		bzero(dir, 32);
		stat(myent->d_name, &mystat);

		bzero(&msgdir, sizeof(msgdir));
		if(S_ISDIR(mystat.st_mode))
		{
			strcpy(dir, "d");
		}
		else
		{
			strcpy(dir, "-");
		}
		sprintf(msgdir.s_buf,"name:%10s,isdir:%5s,size:%d", myent->d_name,
				dir,myent->d_reclen);
		msgdir.s_len = strlen(msgdir.s_buf);
		puts(msgdir.s_buf);
		send(fd_client, &msgdir, msgdir.s_len + MSG_LEN, 0);
	}

	msgdir.s_len = 0;
	send(fd_client, &msgdir, 8188+4, 0);
}

void recv_msg(int fd_client)
{
	printf("ready to recv msg...\n");
	MSG msg;
	
	do
	{
		bzero(&msg, sizeof(MSG));
		recv(fd_client, &msg, 4, 0);
		recv(fd_client, msg.s_buf, msg.s_len, 0);
	}
	while(msg.s_len != 0);
}

void recv_command(int fd_client, char *comd)
{
	printf("ready to recv comd...\n");
	MSG msg;

	recv(fd_client, &msg, 4, 0);
	recv(fd_client, msg.s_buf, msg.s_len, 0);
	
	strcpy(comd, msg.s_buf);
}


void send_path(int fd_client, char *path)
{
	MSG msg;
	dealcd(path);
	
	printf("%s" , path);
	chdir(path);
	sprintf(path, "%s", getcwd(NULL, 0));
	bzero(&msg, sizeof(msg));
	strcpy(msg.s_buf, path);
	msg.s_len = strlen(path);
	send(fd_client, &msg, msg.s_len + MSG_LEN, 0);
	printf("%s", path);

}

void dealcd(char *buf)
{
	int i, j;

	for(i=0, j=3; buf[j] != '\0';j++, i++)
	{
		buf[i] = buf[j];
	}
	buf[i] = '\0';
}
