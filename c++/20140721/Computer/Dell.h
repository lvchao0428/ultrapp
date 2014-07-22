#ifndef DELL_H_
#define DELL_H_ 

#include "Computer.h"

class Dell:public Computer
{
    public:

        Dell(const string &name,
                int cost,
                int weight, 
                const string &type);
        

    private:
        string type_;
};

#endif  /*DELL_H_*/
