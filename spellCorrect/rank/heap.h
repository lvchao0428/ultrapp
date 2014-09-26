#ifndef HEAP_H_
#define HEAP_H_ 

#include "rank.h"
#include <iostream>
#include <vector>

void swap(WORDPAIR &a, WORDPAIR &b);

void HeapAdjust(std::vector<WORDPAIR> &vec, int cur, int heapSize);

void SmallHeap(std::vector<WORDPAIR> &vec, int heapSize);

void HeapInsert(std::vector<WORDPAIR> &vec, WORDPAIR wp);
#endif  /*HEAP_H_*/
