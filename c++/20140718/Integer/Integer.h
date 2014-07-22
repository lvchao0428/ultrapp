

#ifndef INTEGER_H_
#define INTEGER_H_ 


#include <iostream>

class Integer
{
        friend std::ostream &operator<<(std::ostream &os,
                const Integer &obj);
    public:
        Integer(int num);
        ~Integer();

        Integer &operator++();
        Integer operator++(int);
    private:
        int num_;
};




#endif  /*INTEGER_H_*/
