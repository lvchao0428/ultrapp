
#include "Integer.h"

Integer::Integer(int num)
    :num_(num)
{

}

Integer::~Integer()
{

}

Integer &Integer::operator++()
{
    num_++;
    return *this;
}

Integer Integer::operator++(int)
{
    Integer ret(*this);
    ++num_;
    return ret;
}
std::ostream &operator<<(std::ostream &os, const Integer &obj)
{
    os<<obj.num_;

    return os;
}


