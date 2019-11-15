cmake_minimum_required(VERSION 3.14)
project(algs)

add_subdirectory(rpc)


set(CMAKE_CXX_STANDARD 17)

add_executable(algs main.cpp sort/Sort.cpp sort/Sort.h sort/Selection.cpp sort/Selection.h sort/Util.cpp sort/Util.h sort/Insertion.cpp sort/Insertion.h sort/Shell.cpp sort/Shell.h pq/PriorityQueue.cpp pq/PriorityQueue.h pq/MaxPriorityQueue.cpp pq/MaxPriorityQueue.h sort/Item.cpp sort/Item.h tree/SPlayTree.cpp tree/SPlayTree.h tree/BinarySearchTree.cpp tree/BinarySearchTree.h pq/MinPriorityQueue.cpp pq/MinPriorityQueue.h sort/HeapSort.cpp sort/HeapSort.h RadixTree.h tree/BSTNode.cpp tree/BSTNode.h rpc_server.cpp)
add_executable(rpc_server rpc_server.cpp rpc/RPCMethodServer.cpp rpc/RPCMethodServer.h)
add_executable(rpc_client rpc_client.cpp)
target_link_libraries(rpc_client rpc)
target_link_libraries(rpc_server rpc)
target_link_libraries(algs pthread)
target_link_libraries(algs gtest)
