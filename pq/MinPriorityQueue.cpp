//
// Created by developer on 2019/9/9.
//

#include "MinPriorityQueue.h"

int MinPriorityQueue::insert(int value) {
    return PriorityQueue::insert(value);
}

int MinPriorityQueue::delMin() {
    return PriorityQueue::delMin();
}

int MinPriorityQueue::swim(int k) {
    return PriorityQueue::swim(k);
}

int MinPriorityQueue::sink(int k) {
    return PriorityQueue::sink(k);
}
