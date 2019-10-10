//
// Created by developer on 2019/9/2.
//

#ifndef ALGS_SELECTION_H
#define ALGS_SELECTION_H

#include "Sort.h"
#include "Item.h"
template <typename T>
class Selection : public Sort<T> {
public:
    void sort(vector<T> &nums) override
    {
        int size = nums.size();
        for(int i=0; i<size; i++)
        {
            int min = i;
            for (int j=i+1; j<size; j++)
            {

                if(nums[j] < nums[min])
                    min = j;
            }
            diy::swap(nums[i], nums[min]);
        }
    }
};

template <typename Item>
class ItemSelection : public Selection<Item>{
    void sort(vector<Item> &nums, vector<vector<Item>> &steps=vector<vector<Item>>(), bool record = false) override
    {
        int size = nums.size();
        for(int i=0; i<size; i++)
        {
            int min = i;

            for (int j=i+1; j<size; j++)
            {
                if(record)
                {
                    vector<Item> step = nums;
                    step[j].setColor(Color::cmp);
                    step[min].setColor(Color::cmp);
                    steps.push_back(std::move(step));
                }

                if(nums[j] < nums[min])
                {
                    if(record)
                    {
                        vector<Item> step = nums;
                        step[j].setColor(Color::cur);
                        steps.push_back(std::move(step));
                    }
                    min = j;
                }
                else {
                    if(record)
                    {
                        vector<Item> step = nums;
                        step[min].setColor(Color::cur);
                        steps.push_back(std::move(step));
                    }
                }
            }
            if(record)
            {
                vector<Item> step = nums;
                step[i].setColor(Color::swap);
                step[min].setColor(Color::swap);
                steps.push_back(std::move(step));
            }
            diy::swap(nums[i], nums[min]);
            if(record)
            {
                vector<Item> step = nums;
                step[i].setColor(Color::sorted);
                steps.push_back(std::move(step));
            }
        }
    }
};


#endif //ALGS_SELECTION_H
