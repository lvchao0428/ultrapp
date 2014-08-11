#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include "heap.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void swap(WORDPAIR &a, WORDPAIR &b)
{
    WORDPAIR temp;
    temp = a;
    a = b;
    b = temp;
}

void HeapAdjust(vector<WORDPAIR> &vec, int cur, int heapSize)
{
    int leftchild, rightchild, min_num;
    leftchild = 2*cur + 1;
    rightchild = 2*cur + 2;
    if(leftchild < heapSize && vec[leftchild].second < vec[cur].second )
        min_num = leftchild;
    else
        min_num = cur;
    if(rightchild < heapSize && vec[rightchild].second < vec[min_num].second)
        min_num = rightchild;
    if(min_num != cur)
    {
        swap(vec[min_num] , vec[cur]);
        HeapAdjust(vec, min_num, heapSize);
    }
    
}

void SmallHeap(vector<WORDPAIR> &vec, int heapSize)
{
    int i;
    for(i = heapSize/2; i >= 0; i--)
    {
        HeapAdjust(vec, i, heapSize);
    }
}

int find(vector<WORDPAIR> vec, WORDPAIR wp)
{
    vector<WORDPAIR>::iterator it = vec.begin();
    for(; it != vec.end(); ++it)
    {
        if(*it == wp)
            return 1;
    }
    if(it == vec.end())
        return 0;
}

void HeapInsert(vector<WORDPAIR> &vec, WORDPAIR wp)
{
    if( !find(vec, wp))
    {
        vec.push_back(wp);
        SmallHeap(vec, vec.size());
    }
}
