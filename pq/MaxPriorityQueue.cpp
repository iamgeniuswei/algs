//
// Created by developer on 2019/9/4.
//

#include "MaxPriorityQueue.h"
#include <limits.h>
int MaxPriorityQueue::insert(int value) {
    vec.push_back(value);
    int size = vec.size();
    int index = swim(size-1);
    return index;
}

int MaxPriorityQueue::delMax() {
    int size = vec.size();
    if(size == 1)
        return INT_MIN;
    swap(vec[1], vec[size-1]);
    int max = vec[size-1];
    vec.pop_back();
    sink(1);
    return max;
}

int MaxPriorityQueue::delMin() {
    return PriorityQueue::delMin();
}

int MaxPriorityQueue::swim(int k)
{
    while (k > 1 && vec[k] > vec[k/2])
    {
        swap(vec[k], vec[k/2]);
        k /= 2;
    }
    return k;
}

int MaxPriorityQueue::sink(int k)
{
    int size = vec.size();
    while (size > 2*k)
    {
        int j = 2*k;
        if(j<size-1 && vec[j] < vec[j+1])
            j++;
        if(vec[k] > vec[j])
            break;
        swap(vec[k], vec[j]);
        k = j;
    }
}
