#ifndef STRING_H_
#define STRING_H_ 

#include <iostream>
#include <stddef.h>
class String
{
    friend bool operator<(const String &s1, const String &s2);

    friend bool operator>(const String &s1, const String &s2);
    
    friend bool operator<=(const String &s1, const String &s2);

    friend bool operator>=(const String &s1, const String &s2);

    friend bool operator==(const String &s1, const String &s2);

    friend bool operator!=(const String &s1, const String &s2);

    friend String operator+(const String &, const String &);
    friend String operator+(const String &, const char *);
//    friend String operator+(const char *, const char *);

    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::istream &operator>>(std::istream &, String &);
    public:
        String();
        String(const String &);
        String(const char *);

        String &operator=(const String &);
        String &operator=(const char *);

        String &operator+=(const String &);
        String &operator+=(const char *);

        char &operator[] (size_t index);
        char operator[](size_t index) const;

        size_t size() const;

        const char *c_str() const;
        
        void debug() const;

        ~String();
    private:
        char *str_;
};
inline String operator+(const String &s1, const String &s2)
{
    String ret(s1);
    ret += s2;

    return ret;
}
    
inline String operator+(const String &s1, const char *s2)
{
    return s1 + String(s2);
}

inline std::ostream &operator<<(std::ostream &os, const String &s)
{
    return os << s.str_;
}
inline std::istream &operator>>(std::istream &is, String &s)
{
    char buf[1024];
    is >> buf;
    if(is)
    {
        s = buf;
    }

    return is;
}
 
#endif  /*STRING_H_*/