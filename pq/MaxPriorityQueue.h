//
// Created by developer on 2019/9/4.
//

#ifndef ALGS_MAXPRIORITYQUEUE_H
#define ALGS_MAXPRIORITYQUEUE_H

#include "PriorityQueue.h"

class MaxPriorityQueue : public PriorityQueue{
public:
    int insert(int value) override;

    int delMax() override;

    int delMin() override;

protected:
    int swim(int k) override;

    int sink(int k) override;

};


#endif //ALGS_MAXPRIORITYQUEUE_H
