#include "rio.h"

#include <stdlib.h>
#include <string.h>

Rio::Rio(int fd,char* usrbuf,size_t n)
{
    fd_ = fd;
    usrbuf_ = (char *)malloc(sizeof(strlen(usrbuf)));
    strcpy(usrbuf_, usrbuf);
    n_ = n;
}


Rio::~Rio()
{
    free(usrbuf_);
}




ssize_t Rio::readn()
{
    size_t nleft = n_; //表示还需要读取的字节数
    ssize_t nread;
    char *bufp = usrbuf_; //控制read函数存放的位置

    while(nleft > 0)
    {
        if((nread = read(fd_, bufp, nleft)) == -1)
        {
            if(errno == EINTR)  //interupt
                nread = 0;  //continue;  中断需要再次读取
            else
                return -1;  // ERROR
        }else if(nread == 0)  // EOF
            break;
        
        nleft -= nread;
        bufp += nread;
    }
    return (n_ - nleft);
}

ssize_t Rio::writen()
{
    size_t nleft = n_;
    ssize_t nwrite;

    char *bufp = usrbuf_;

    while(nleft > 0)
    {
        //nwrite == 0也属于错误
        if((nwrite = write(fd_, bufp, nleft)) <= 0)
        {
            if(errno == EINTR)
                nwrite = 0;
            else
                return -1; // -1 和 0
        }

        nleft -= nwrite;
        bufp += nwrite;
    }
    return n_;  //这里不是 n- nleft 必须是n
}

//recv_peek选项完成一次正确的读取过程。
ssize_t Rio::recv_peek() {
    int nread;
    while (1) {
        //这个过程只成功调用一次
        nread = recv(sockfd_, usrbuf_, n_, MSG_PEEK);
        if (nread < 0 && errno == EINTR) {  //被中断则继续读取
            continue;
        }
        if (nread < 0) {
            return -1;
        }
        break;
    }
    return nread;
}


ssize_t Rio::readline() {
    int nread;  //一次IO读取的数量
    int nleft;  //还剩余的字节数
    char *ptr;  //存放数据的指针的位置
    int ret;    //readn的返回值
    int total = 0;  //目前总共读取的字节数

    nleft = n_-1;
    ptr = usrbuf_;

    while (nleft > 0) {
        //这一次调用仅仅是预览数据
        //并没有真的把数据从缓冲区中取走
        ret = recv_peek(fd_, ptr, nleft);
        //注意这里读取的字节不够，绝对不是错误！！！
        if (ret <= 0) {
            return ret;
        }

        nread = ret;
        int i;
        for (i = 0; i < nread; ++i) {
            if (ptr[i] == '\n') {
                //这里才是真正的读取过程
                ret = readn(fd_, ptr, i + 1);
                if (ret != i + 1) {
                    return -1;
                }
                total += ret;
                ptr += ret;
                *ptr = 0;
                return total;   //返回此行的长度 '\n'包含在其中
            }
        }
        //如果没有发现\n，这些数据应全部接收
        ret = readn(fd_, ptr, nread);
        if (ret != nread) {
            return -1;
        }
        nleft -= nread;
        total += nread;
        ptr += nread;
    }
    *ptr = 0;
    return n_-1;
}



