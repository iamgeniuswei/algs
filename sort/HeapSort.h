//
// Created by developer on 2019/9/9.
//

#ifndef ALGS_HEAPSORT_H
#define ALGS_HEAPSORT_H

#include "Sort.h"
template <typename T>
class HeapSort : public Sort<T> {
public:
    void sort(vector<T> &nums) override
    {
        int size = nums.size();
        for(int k=size/2; k>=1; k--)
        {
            sink(nums, k, size);
        }
        while(size > 1)
        {
            swap(nums[1], nums[size-1]);
            size--;
            sink(nums, 1, size);
        }
        
    }

protected:
    void sink(vector<T>&nums, int k, int size)
    {
        while (size > 2*k)
        {
            int j = 2*k;
            if(j<size-1 && nums[j] < nums[j+1])
                j++;
            if(nums[k] > nums[j])
                break;
            swap(nums[k], nums[j]);
            k = j;
        }
    }

};


#endif //ALGS_HEAPSORT_H
