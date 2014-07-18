
#include "String.h"
#include <iostream>
#include <string.h>

using namespace std;
String::String():
    str_(new char[1])
{
    str_[0] = '\0';
}

void String::debug() const
{
    cout << str_ <<endl;
}

String::String(const String &s)
    :str_(new char[s.size() + 1])
{
    ::strcpy(str_,s.str_);
}

String::String(const char *s)
    :str_(new char[strlen(s) + 1])
{
    ::strcpy(str_, s);
}

String &String::operator=(const String &s)
{
    if(this != &s)
    {
        delete[]str_;
        str_ = new char[s.size() + 1];
        ::strcpy(str_, s.str_);
    }
}

String &String::operator=(const char *s)
{
    if(str_ != s)
    {
        delete[] str_;
        str_ = new char[strlen(s) + 1];
        ::strcpy(str_, s);
    }
}


String &String::operator+=(const String &s)
{
    char *pt = new char[size() + s.size() + 1];
    ::strcpy(pt, str_);
    ::strcat(pt, s.str_);

    delete str_;

    str_ = pt;

    return *this;
}

String &String::operator+=(const char *s)
{
    return operator+=(String(s));
}

char &String::operator[] (size_t index)
{
    return str_[index];
}
char String::operator[](size_t index) const
{
    return str_[index];
}

size_t String::size() const
{
    return ::strlen(str_);
}

const char *String::c_str() const
{
    return str_;
}


String::~String()
{
    delete str_;
}

bool operator<(const String &s1, const String &s2)
{
    return ::strcmp(s1.str_, s2.str_) < 0;
}

bool operator>(const String &s1, const String &s2)
{
    return ::strcmp(s1.str_, s2.str_) > 0;
}

bool operator<=(const String &s1, const String &s2)
{
    return !(s1 > s2);
}

bool operator>=(const String &s1, const String &s2)
{
    return !(s1 < s2) ;
}

bool operator==(const String &s1, const String &s2)
{
    return ::strcmp(s1.str_, s2.str_) == 0;
}

bool operator!=(const String &s1, const String &s2)
{
    return !(s1 == s2);
}



//inline  friend String operator+(const char *s1, const char *s2)
//{
//    String ret(String(s1));
 //   ret + = String(s2);
 //   return ret;
//}


