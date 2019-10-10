//
// Created by developer on 2019/9/4.
//

#ifndef ALGS_PRIORITYQUEUE_H
#define ALGS_PRIORITYQUEUE_H

#include <vector>
using namespace std;

class PriorityQueue {
public:
    PriorityQueue();
    virtual int insert(int value);
    virtual int delMax();
    virtual int delMin();

protected:
    virtual int swim(int k);
    virtual int sink(int k);

protected:
    vector<int> vec;
};


#endif //ALGS_PRIORITYQUEUE_H
