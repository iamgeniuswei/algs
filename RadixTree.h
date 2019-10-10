//
// Created by developer on 2019/9/12.
//

#ifndef ALGS_RADIXTREE_H
#define ALGS_RADIXTREE_H

#define LOG2_NODES_PER_LEVEL    10
#define NODES_PER_LEVEL         (1 << LOG2_NODES_PER_LEVEL)

#define LEAF_INDEX(framenum) \
        (((framenum) >> (0*LOG2_NODES_PER_LEVEL)) & (NODES_PER_LEVEL-1))


struct _frame_data_sequence{
    int count;
    void *root;
};

struct frame_data{
    int a;
    int b;
    int c;
    int d;
};

#endif //ALGS_RADIXTREE_H
