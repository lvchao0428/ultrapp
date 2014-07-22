#ifndef COMPLEX
#define COMPLEX 

#include <iostream>
#include <iomanip>

class Complex
{
    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c1, const Complex &c2);
    friend Complex operator*(const Complex &c1, const Complex &c2);
    friend Complex operator/(const Complex &c1, const Complex &c2);

    friend std::ostream &operator<<(std::ostream &os, const Complex &c);
    friend std::istream &operator>>(std::istream &is,  Complex &c);

    public:
            
        Complex();
        Complex(const Complex &c);

        Complex &operator=(const Complex &c);

    private:
        double imgPart_;
        double realPart_;
};
inline Complex operator+(const Complex &c1, const Complex &c2)
{
    Complex ret;
    ret.imgPart_ = c1.imgPart_ + c2.imgPart_;
    ret.realPart_ = c1.realPart_ + c2.realPart_;
    return ret;
}

inline Complex operator-(const Complex &c1, const Complex &c2)
{
    Complex ret;
    ret.realPart_ = c1.realPart_-c2.realPart_;
    ret.imgPart_ = c1.imgPart_ - c2.imgPart_;
    return ret;
}

inline Complex operator*(const Complex &c1, const Complex &c2)
{
    Complex ret;
    
    //real part  
    ret.realPart_ = c1.realPart_*c2.realPart_ - c1.imgPart_*c2.imgPart_;
    //img part
    ret.imgPart_ = c1.imgPart_ *c2.realPart_ + c1.realPart_*c2.imgPart_;
    return ret;
}

inline Complex operator/(const Complex &c1, const Complex &c2)
{
    Complex ret;
    double a = c1.realPart_;
    double b = c1.imgPart_;
    double c = c2.realPart_;
    double d = c2.imgPart_;
    //real part
    ret.realPart_ = (a*c + b*d)/(c*c + d*d);
    ret.imgPart_ = (b*c - a*d)/(c*c + d*d);

    return ret;
}

inline std::ostream &operator<<(std::ostream &os, const Complex &c)
{
    if(c.imgPart_ > 0)
        return os <<std::setprecision(2)<< c.realPart_ << "+"<<c.imgPart_ <<"i";
    else
        return os <<std::setprecision(2)<< c.realPart_<<c.imgPart_<<"i";
}


inline std::istream &operator>>(std::istream &is,Complex &c)
{
    double realPart, imgPart;
    is >> realPart >> imgPart;
    if(is)
    {
        c.realPart_ = realPart;
        c.imgPart_ = imgPart;
    }

    return is;
}



#endif  /*COMPLEX*/
