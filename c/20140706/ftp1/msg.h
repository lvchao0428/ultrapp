
#ifndef __MSG_H_
#define __MSG_H_
#define MSG_SIZE 8188 
#define MSG_LEN 4
typedef struct sockaddr_in SA;
typedef struct tag
{
	int s_len ;		//msg 实际上长度
	char s_buf[MSG_SIZE];
}MSG;



#endif
