#ifndef TIMERTHREAD_H_
#define TIMERTHREAD_H_ 
#include "NonCopyable.h"
#include "thread.h"
#include "timer.h"
#include <functional>

class TimerThread : private NonCopyable
{
    public:
        typedef std::function<void()> TimerCallback;
        void setTimer(int value, int interval);
        void setTimerCallback(const TimerCallback &cb);
        void startTimerThread();
        void cancelTimerThread();

    private:
        Timer timer_;
        Thread thread_;
            
};


#endif  /*TIMERTHREAD_H_*/

