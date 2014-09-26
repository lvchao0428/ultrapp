#include <linux/tty.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <linux/sockios.h>
#include <stdio.h>
#include <linux/kd.h>
#include <sys/io.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    int tty_fd = open("/dev/console", O_NOCTTY);
//    ioctl(tty_fd, KDSETLED, LED_NUM | LED_CAP | LED_SCR);
    if(tty_fd < 0)
    {
        perror("open");
        exit(0);
    }

    while(1)
    {   int i;
        for (i = 0; i < 1000; i++) ;
        ioctl(tty_fd, KDSETLED, 0x1);
        for (i = 0; i < 1000; i++) ;
        ioctl(tty_fd, KDSETLED, 0x2);
        for (i = 0; i < 1000; i++) ;
        ioctl(tty_fd, KDSETLED, 0x4);
    }
    getchar();

    return 0;
}
