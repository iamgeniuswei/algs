//
// Created by developer on 2019/9/9.
//

#ifndef ALGS_MINPRIORITYQUEUE_H
#define ALGS_MINPRIORITYQUEUE_H

#include "PriorityQueue.h"

class MinPriorityQueue : public PriorityQueue{
public:
    int insert(int value) override;

    int delMin() override;

protected:
    int swim(int k) override;

    int sink(int k) override;

};


#endif //ALGS_MINPRIORITYQUEUE_H
