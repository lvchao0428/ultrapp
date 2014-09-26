
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void SignChidPsExit(int iSignNo)
{
    int iExitCode;
    pid_t pid = waitpid(-1, NULL, 0);
    printf("SignNo:%d  child :%d exit\n", iSignNo, pid);

    if(WIFEXITED(iExitCode))
    {
        printf("chid exited with code %d\n", WEXITSTATUS(iExitCode));
    }
    sleep(10);


}

int main(int argc, const char *argv[])
{
    signal(SIGCHLD, SignChidPsExit);

    printf("Parent process id:%d\n", getpid());

    pid_t iRet = fork();
    if(iRet == 0)
        exit(3);

    return 0;
}
