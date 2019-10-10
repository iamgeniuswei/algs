//
// Created by developer on 2019/9/2.
//

#ifndef ALGS_SHELL_H
#define ALGS_SHELL_H

#include "Sort.h"
template <typename T>
class Shell : public Sort<T>{
public:
    void sort(vector<int> &nums) override
    {
        int size = nums.size();
        int h = 1;
        while (h <= size)
            h = 3*h + 1;
        while (h>=1)
        {
            for(int i=h; i<size; i++)
            {
                for(int j=i; j>=h && nums[j] < nums[j-h]; j -= h)
                {
                    diy::swap(nums[j], nums[j-h]);
                }
            }
            h /= 3;
        }
    }

};


#endif //ALGS_SHELL_H
