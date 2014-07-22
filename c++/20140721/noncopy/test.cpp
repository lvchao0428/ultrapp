
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NonCopyable
{
    public:
        NonCopyable(){}
        ~NonCopyable(){}
    private:
        NonCopyable(const NonCopyable &);
        void operator=(const NonCopyable &);
};

class Test : private NonCopyable
{
    
};

int main(int argc, const char *argv[])
{
    Test t;
    Test t2(t);

    Test t3;
    t3 = t;
    return 0;
}
