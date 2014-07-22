
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *threadFunc(void* pArg)
{
    int iArg = (int)pArg;
    sleep(iArg);
    if(iArg < 3)
    {
        return (void*)(iArg*2);
    }
    else
    {
        pthread_exit((void*)(iArg*2));
    }


}

int main(int argc, const char *argv[])
{
    pthread_t thdId;
    int iRet = 0;
    pthread_create(&thdId, NULL, threadFunc, (void*)2);
    pthread_join(thdId, (void**)&iRet);
    printf("The first child thread ret is:%d\n", iRet);
    pthread_create(&thdId, NULL, threadFunc, (void*)4);
    pthread_join(thdId, (void**)&iRet);
    printf("The second child thread ret is:%d\n", iRet);

    return 0;
}
