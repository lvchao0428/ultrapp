   
#include "Complex.h"

using namespace std;

Complex::Complex():
    realPart_(0),
    imgPart_(0)
{
}

Complex::Complex(const Complex &c):
    realPart_(c.realPart_),
    imgPart_(c.imgPart_)
{

}

Complex &Complex::operator=(const Complex &c)
{
    if(this != &c)
    {
        realPart_ = c.realPart_;
        imgPart_ = c.imgPart_;
        return *this;
    }
}




