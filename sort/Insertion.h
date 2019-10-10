//
// Created by developer on 2019/9/2.
//

#ifndef ALGS_INSERTION_H
#define ALGS_INSERTION_H

#include "Sort.h"
template <typename T>
class Insertion : public Sort<T>{
public:
    void sort(vector<T> &nums) override{
        int size = nums.size();
        for(int i=1; i<size; i++)
        {
            for(int j=i; j>0 && nums[j-1] > nums[j]; j--)
            {
                diy::swap(nums[j-1], nums[j]);
            }
        }
    }
};


#endif //ALGS_INSERTION_H
