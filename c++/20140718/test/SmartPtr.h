#ifndef SMARTPTR
#define SMARTPTR 

#include <iostream>

#define DISALLOW_COPY_ASSIGN(TypeName) \
    TypeName(const TypeName &); \
    void operator=(const TypeName&)

class Animal
{
    public:
        Animal()
        {
            std::cout <<"construct....."<<std::endl;
        }

        ~Animal()
        {
            std::cout<<"destruct ... "<<std::endl;
        }

        void run()
        {
            std::cout<< "running......"<<std::endl;
        }
};

class SmartPtr
{
    public:
        SmartPtr(Animal *ptr);
        ~SmartPtr();
        
        Animal &operator*();
        const Animal &operator*() const;

        Animal *operator->();
        const Animal *operator->()const;
    private:
        
        DISALLOW_COPY_ASSIGN(SmartPtr);
        Animal *ptr_;
};

#endif  /*SMARTPTR*/
