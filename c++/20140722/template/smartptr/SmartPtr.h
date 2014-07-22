
#ifndef SMARTPTR_H_
#define SMARTPTR_H_ 

#include <iostream>

class Animal
{
    public:
        Animal()
        {
            std::cout<<"Animal.."<<std::endl;
        }
        ~Animal()
        {
            std::cout<<"~Animal.."<<std::endl;
        }
};


class SmartPtr
{
    public:
        SmartPtr();
        explicit SmartPtr(Animal *ptr);
        ~SmartPtr();

        void resetPtr(Animal *ptr);
        const Animal *getPtr() const;

        Animal &operator*();
        const Animal &operator*() const;

        Animal *operator->();
        const Animal *operator->() const;

    private:
        SmartPtr(const SmartPtr&);
        void operator=(const SmartPtr &);

        Animal *ptr_;
};
#endif  /*SMARTPTR_H_*/
