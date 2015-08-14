#ifndef __STRING_H_
#define __STRING_H_

class String
{
public:
    String(){ m_data = new char[1]; *m_data = '\0'; };
    String(const char* cstr);
    String(const String& other);
    String& operator=(const String& other);
    ~String();

    char* get_c_str()const { return m_data; }    
private:
    char* m_data;
};

#include<cstring>

inline
String::String(const char* cstr)
{
    if(cstr)
    {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline 
String::String(const String& other)
{
    m_data = new char[strlen(other.m_data) + 1];
    strcpy(m_data, other.m_data);
}

inline
String& String::operator=(const String& other)
{
    if(this == &other)
    {
        return *this;
    }
    delete[] m_data;
    m_data = new char[strlen(other.m_data) + 1];
    strcpy(m_data, other.m_data);
    return *this;
}

inline 
String::~String()
{
    delete[] m_data;
}

#include<iostream>
using namespace std;

inline 
ostream& operator<<(ostream& os, const String& str)
{
    os << str.get_c_str();
    return os;
}

#endif
