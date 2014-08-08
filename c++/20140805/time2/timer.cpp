#include "timer.h"
#include <poll.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_EXIT(m) \
    do \
    {\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)

Timer::Timer()
    :is_Started_(false)
{
    timerfd_ = ::timerfd_create(CLOCK_REALTIME, 0);
    if(timerfd_ == -1)
        ERR_EXIT("timerfd_create");
    memset(&howlong_, 0, sizeof howlong_);
}

Timer::~Timer()
{
    ::close(timerfd_);
}

void Timer::setTimer(int val, int interval)
{
    howlong_.it_value.tv_sec = val;
    howlong_.it_interval.tv_sec = interval;
}

void Timer::setTimeCallback(const TimeCallback &cb)
{
    timeCallback_ = cb;
}

void Timer::runTimer()
{
    struct pollfd event[1];
    event[0].fd= timerfd_;
    event[0].events = POLLIN;
    char buf[1024];
    int nready;

    if(timerfd_settime(timerfd_, 0, &howlong_, NULL) == -1)
        ERR_EXIT("timerfd_settime");
    
    is_Started_ = true;
    while(is_Started_)
    {
    
        nready = poll(event, 1, 10000);
        if(nready == -1)
        {
            ERR_EXIT("poll");
            
        }
        else if(nready == 0)
            printf("timeout\n");
        else
        {
            if(read(timerfd_, buf, sizeof buf) == -1)
                ERR_EXIT("read");
            timeCallback_();
        }
    }

}

void Timer::cancelTimer()
{
    memset(&howlong_, 0, sizeof howlong_);
    if(timerfd_settime(timerfd_, 0, &howlong_, NULL) == -1)
        ERR_EXIT("timerfd_settime");
    is_Started_ = false;
}
