
#include "Dell.h"

Dell::Dell(const string &name,
        int cost,
        int weight,
        const string &type):
    Computer(name, cost, weight),
    type_(type)
{
    
}


