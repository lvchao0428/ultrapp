#ifndef __COMPLEX_H_
#define __COMPLEX_H_

class mycomplex;
mycomplex&
    __doapl (mycomplex* ths, const mycomplex& r);

mycomplex&
    __doami (mycomplex* ths, const mycomplex& r);
mycomplex&
    __doaml (mycomplex* ths, const mycomplex& r);

class mycomplex
{
public:
    mycomplex (double r = 0, double i = 0): re(r), im(i) { }
    mycomplex& operator += (const mycomplex&);
    mycomplex& operator -= (const mycomplex&);
    mycomplex& operator *= (const mycomplex&);
    mycomplex& operator /= (const mycomplex&);
    double real() const { return re; }
    double imag() const { return im; }


private:
    double re, im;

    friend mycomplex& __doapl (mycomplex*, const mycomplex&);
    friend mycomplex& __doami (mycomplex*, const mycomplex&);
    friend mycomplex& __doaml (mycomplex*, const mycomplex&);



};

#include<iostream>
using namespace std;

inline ostream&
operator<<(ostream& os, const mycomplex& r)
{
    os << '(' << r.real() << ',' << r.imag() << ')';
    return os;
}


inline mycomplex&
__doapl (mycomplex* ths, const mycomplex& r)
{
    ths->re += r.re;
    ths->im += r.im;

    return *ths;
}

inline mycomplex&
__doami (mycomplex* ths, const mycomplex& r)
{
    ths->re -= r.re;
    ths->im -= r.im;

    return *ths;
}

inline mycomplex&
__doaml(mycomplex* ths, const mycomplex& r)
{
    ths->re *= r.re;
    ths->im *= r.im;

    return *ths;
}

inline
mycomplex& mycomplex::operator += (const mycomplex& r)
{
    this->re += r.re;
    this->im += r.im;

    return *this;
}

inline 
mycomplex& mycomplex::operator -= (const mycomplex& r)
{
    this->re -= r.re;
    this->im -= r.im;

    return *this;
}

inline 
mycomplex& mycomplex::operator *= (const mycomplex& r)
{
    this->re *= r.re;
    this->im *= r.im;

    return *this;
}

#include<assert.h>

inline
mycomplex& mycomplex::operator /= (const mycomplex& r)
{
    assert(r.re != 0 && r.im != 0);
    
    this->re /= r.re;
    this->im /= r.im;

    return *this;

}

inline mycomplex
operator+(const mycomplex& x, const mycomplex& y)
{
    return mycomplex(x.real() +y.real(), x.imag()+y.imag());
}



#endif
