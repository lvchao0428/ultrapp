
#include <stdexcept>
#include <iostream>

using namespace std;

class Test
{
    public:
        Test()
        {
            cout<<"construt....."<<endl;
        }

        ~Test()
        {
            cout<<"destruct....."<<endl;
        }
};

int main(int argc, const char *argv[])
{
    try
    {
        Test t[3];
        throw runtime_error("error");
    }
    catch(runtime_error &e)
    {
        cout<<e.what()<<endl;
    }
    

    return 0;
}
