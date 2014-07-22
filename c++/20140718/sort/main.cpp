
#include "sort.h"
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    int a[5];


    int i;
    for (i = 0; i < 5; i++) 
    {
        cin>>a[i];
    }

//    bubble_sort(a, 5);

//    select_sort(a, 5) ;
    
//    insert_sort(a, 5);
    quick_sort(a, 5);       
    show(a, 5);
    
    return 0;
}
