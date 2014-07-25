
#include <unistd.h>

int main(int argc, const char *argv[])
{
    if((write(1, "here is come data\n", 18)) != 18)
        write(2, "A write error has occured onfile descriptor 1\n", 46);
    return 0;
}
