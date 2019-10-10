cmake_minimum_required(VERSION 3.14)
project(algs)

set(CMAKE_CXX_STANDARD 17)

add_executable(algs main.cpp sort/Sort.cpp sort/Sort.h sort/Selection.cpp sort/Selection.h sort/Util.cpp sort/Util.h sort/Insertion.cpp sort/Insertion.h sort/Shell.cpp sort/Shell.h pq/PriorityQueue.cpp pq/PriorityQueue.h pq/MaxPriorityQueue.cpp pq/MaxPriorityQueue.h sort/Item.cpp sort/Item.h tree/SPlayTree.cpp tree/SPlayTree.h tree/BinarySearchTree.cpp tree/BinarySearchTree.h pq/MinPriorityQueue.cpp pq/MinPriorityQueue.h sort/HeapSort.cpp sort/HeapSort.h RadixTree.h)
target_link_libraries(algs pthread)
target_link_libraries(algs gtest)
