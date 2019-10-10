//
// Created by developer on 2019/9/2.
//

#ifndef ALGS_SORT_H
#define ALGS_SORT_H

#include <vector>
#include <iostream>
using namespace std;
namespace diy
{
    template <typename T>
    void swap(T &a, T &b) {
        T temp = a;
        a = b;
        b = temp;
    }
}


template <typename T>
class Sort {
public:
    virtual void sort(vector<T>& nums, vector<vector<T>> &steps = vector<vector<T>>(), bool record = false) {};
    virtual void sort(vector<T>& nums){};
    bool isSorted(vector<T>& nums)
    {
        int size = nums.size();
        cout << "size is: " << size << endl;
        for(int i=1; i<size; i++)
        {
            if(nums[i-1] > nums[i])
                return false;
        }
        return true;
    }

    void printAll(vector<T> &nums)
    {
        int size = nums.size();
        for (int i=0; i<size; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};


#endif //ALGS_SORT_H
