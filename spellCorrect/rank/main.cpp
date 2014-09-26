#include "rank.h"
#include <iostream>

int main(int argc, const char *argv[])
{
    Rank rk("rank_bible.txt");
    rk.compute();

    return 0;
}
