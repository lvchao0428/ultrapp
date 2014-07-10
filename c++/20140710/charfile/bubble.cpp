/*************************************************************************
	> File Name: bubble.cpp
	> Author: lvchao
	> Mail:lvchao0428@163.com 
	> Created Time: Thu 10 Jul 2014 04:58:20 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

inline void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool cmp(int a, int b)
{
    return a>b;
}

void bubble_sort(vector<int> &vec, bool (*cmp)(int, int))
{
    auto len = vec.size();
    int i, j;
    for (i = 0; i < len-1; i++) 
    {
        for (j = 0; j < len-1-i; j++) 
        {
            if(cmp(vec[j], vec[j+1]))
                swap(vec[j], vec[j+1]);
        }
        
    }
    
}

void bubble_sort1(vector<int> &vec, bool (*cmp)(int, int))
{
    auto len = vec.size();

    int left=0, right = len -1;
    while(left < right)
    {
        for(size_t i = left;i != right; ++i)
        {
            if(cmp(vec[i], vec[i+1]))
                swap(vec[i], vec[i+1]);
        }
        right--;
        for(size_t i = right; i != left; --i)
        {
            if(!cmp(vec[i], vec[i-1]))
                swap(vec[i], vec[i-1]);
        }
        left++;
    }
}

int main(int argc, const char *argv[])
{
    vector<int> vec;
    srand(time(NULL));

    for(int i = 0; i<10; ++i)
    {
        vec.push_back(rand()%100);
    }

//    bubble_sort(vec, cmp);
    bubble_sort1(vec,cmp);
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        cout << *it <<' ';    
    }
    cout<<endl;

    return 0;
}
