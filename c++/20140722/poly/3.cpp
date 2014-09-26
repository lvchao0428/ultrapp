
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Test
{
    public:

        int a_;
        virtual void test();
};

int main(int argc, const char *argv[])
{
    cout<<sizeof(Test)<<endl;

    return 0;
}


