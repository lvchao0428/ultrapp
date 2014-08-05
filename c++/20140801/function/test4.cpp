#include <iostream>
#include <string>
#include <functional>

using namespace std;

void test(int i, double d, const string &s)
{
    cout << "i = "<<i<<"d = "<<d<<"s = "<<s<<endl;
}

int main(int argc, const char *argv[])
{
    //1.void(*)(int, double)
    function<void(int, double)> fp;
    string s = "foobar";
    fp = bind(&test,
            std::placeholders::_1,
            std::placeholders::_2,
            s);
    fp(100, 3.456);
    //2.void(*)(double,int,const string&)
    function<void(double,int, const string &)> fp2;
    fp2 = bind(&test,
            std::placeholders::_2,
            std::placeholders::_1,
            std::placeholders::_3);
    fp2(3.1415926, 23456, "foobar");
    //3.void(*)(const string &,int)

     function<void(const string&, int)>   fp3;
    double d = 3.14;
    fp3 = bind(&test,
            std::placeholders::_2,
            d,
            std::placeholders::_1);
    fp3("hello", 123 );
    //4.void(*)(const string &, int ,double)
    function<void(const string&, int, double)> fp4;
    fp4 = bind(&test,
            std::placeholders::_2,
            std::placeholders::_3,
            std::placeholders::_1);
    fp4("hello", 3, 3.14);

    //5. void(*)(int )
    function<void(int)> fp5;
    double d2 = 4.68;
    string s2 = "how are you";
    fp5 = bind(&test,
            std::placeholders::_1,
            d2,
            s2);
    fp5(1);
    //5.5 void(*)(const string &)
    function<void(const string &)> fp6;
    int i2 = 55;
    double d3 = 7.89;
    fp6 = bind(&test,
            i2,
            d3,
            std::placeholders::_1);
    fp6("sodoku");
    //void (*)()
    function<void()> fp7;
    int i3 = 123;
    double d4 = 6.23;
    string s4 = "soga";
    fp7 = bind(&test,
            i3,
            d4,
            s4);
    fp7();
    return 0;
}
