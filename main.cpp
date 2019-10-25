#include <iostream>
#include <vector>
using namespace std;
#include <gtest/gtest.h>
#include "sort/Selection.h"
#include "sort/Insertion.h"
#include "sort/Shell.h"
#include "sort/Util.h"
#include "pq/MaxPriorityQueue.h"
#include "sort/HeapSort.h"
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testSelection, test_sort1)
{
    cout << "testSelection_test_sort2" << endl;
    vector<int> nums{5, 4, 3, 2, 1};
    Selection<int> selection;
    selection.printAll(nums);
    selection.sort(nums);
    selection.printAll(nums);
    EXPECT_EQ(selection.isSorted(nums), true);
    cout << "end" << endl;
}

TEST(testSelection, test_sort2)
{
    cout << "testSelection_test_sort2" << endl;
    vector<int> nums{1, 2, 3, 4, 5};
    Selection<int> selection;
    selection.printAll(nums);
    selection.sort(nums);
    selection.printAll(nums);
    EXPECT_EQ(selection.isSorted(nums), true);
    cout << "end" << endl;
}

//TEST(testSelection, test_sort_10m)
//{
//    cout << "testSelection_test_sort_10m" << endl;
//    string path = "/home/developer/Project/Code/algs/data/largeW.txt";
//    vector<int> nums = Util::readData(path);
//    auto start = system_clock::now();
//    Selection<int> selection;
////    selection.printAll(nums);
//    selection.sort(nums);
//    auto end = system_clock::now();
//    Util::timeElapsed(start, end);
////    selection.printAll(nums);
//    EXPECT_EQ(selection.isSorted(nums), true);
//    cout << "end" << endl;
//}

TEST(testShell, test_sort1)
{
    cout << "testShell_test_sort2" << endl;
    vector<int> nums{5, 4, 3, 2, 1};
    Shell<int> shell;
    shell.printAll(nums);
    shell.sort(nums);
    shell.printAll(nums);
    EXPECT_EQ(shell.isSorted(nums), true);
    cout << "end" << endl;
}

//TEST(testShell, test_sort_10m)
//{
//    cout << "testShell_test_sort_10m" << endl;
//    string path = "/home/developer/Project/Code/algs/data/largeW.txt";
//    vector<int> nums = Util::readData(path);
//    auto start = system_clock::now();
//    Shell<int> selection;
////    selection.printAll(nums);
//    selection.sort(nums);
//    auto end = system_clock::now();
//    Util::timeElapsed(start, end);
////    selection.printAll(nums);
//    EXPECT_EQ(selection.isSorted(nums), true);
//    cout << "end" << endl;
//}

TEST(testInsertion, test_sort1)
{
    cout << "testInsertion_test_sort2" << endl;
    vector<int> nums{5, 4, 3, 2, 1};
    Insertion<int> selection;
    selection.printAll(nums);
    selection.sort(nums);
    selection.printAll(nums);
    EXPECT_EQ(selection.isSorted(nums), true);
    cout << "end" << endl;
}

TEST(testInsertion, test_sort2)
{
    cout << "testInsertion_test_sort2" << endl;
    vector<int> nums{1, 2, 3, 4, 5};
    Insertion<int> selection;
    selection.printAll(nums);
    selection.sort(nums);
    selection.printAll(nums);
    EXPECT_EQ(selection.isSorted(nums), true);
    cout << "end" << endl;
}

//TEST(testInsertion, test_sort_10m)
//{
//    cout << "testInsertion_test_sort_10m" << endl;
//    string path = "/home/developer/Project/Code/algs/data/largeW.txt";
//    vector<int> nums = Util::readData(path);
//    auto start = system_clock::now();
//    Insertion<int> selection;
////    selection.printAll(nums);
//    selection.sort(nums);
//    auto end = system_clock::now();
//    Util::timeElapsed(start, end);
////    selection.printAll(nums);
//    EXPECT_EQ(selection.isSorted(nums), true);
//    cout << "end" << endl;
//}

TEST(testMaxPQ, test_insert)
{
    MaxPriorityQueue maxPQ;
    for(int i=1; i<=5; i++)
        maxPQ.insert(i);
    EXPECT_EQ(true, true);
}

TEST(testMaxPQ, test_delMax)
{
    MaxPriorityQueue maxPQ;
    for(int i=1; i<=5; i++)
        maxPQ.insert(i);
    for(int i=7; i>=0; i--)
        cout << maxPQ.delMax() << endl;
    EXPECT_EQ(true, true);

}

#include "sort/Item.h"
#include <random>
using std::default_random_engine;
TEST(testItem, test_sort)
{
    vector<Item> nums;
    default_random_engine e;
    for(int i=15; i>=0; i--)
    {
        Item item(e()%1000);
        nums.push_back(item);
    }
    Selection<Item> selection;
    selection.sort(nums);
    selection.printAll(nums);
    EXPECT_EQ(selection.isSorted(nums), true);
}

TEST(testHeapSort, test_sort)
{
    vector<int> nums;
    nums.push_back(0);
    default_random_engine e;
    for(int i=15; i>=0; i--)
    {

        nums.push_back(e()%1000);
    }
    HeapSort<int> selection;
    selection.sort(nums);
    selection.printAll(nums);
    EXPECT_EQ(selection.isSorted(nums), true);
}

#include "RadixTree.h"

TEST(testRadixTree, testDefine)
{
    frame_data *leaf;
    frame_data **level1;
    int framenum = 1024;
    int out = LEAF_INDEX(framenum);
    cout << endl << out << endl;
    EXPECT_EQ(sizeof(frame_data), 16);
    EXPECT_EQ(sizeof(*leaf), 16);
    EXPECT_EQ(sizeof(*level1), 8);
    EXPECT_EQ(NODES_PER_LEVEL, 1024);
}

#include "tree/BSTNode.h"
TEST(testTree, testBSTNode_isRoot)
{
    BSTNode node;
    EXPECT_EQ(node.isRoot(), true);
    EXPECT_EQ(node.isLChild(), false);
    EXPECT_EQ(node.isRChild(), false);
    EXPECT_EQ(node.hasLChild(), false);
    EXPECT_EQ(node.hasRChild(), false);
    EXPECT_EQ(node.hasChild(), false);
    EXPECT_EQ(node.hasParent(), false);
    EXPECT_EQ(node.hasBothChild(), false);
    EXPECT_EQ(node.isLeaf(), false);
    EXPECT_EQ(node.sibling(), nullptr);
    EXPECT_EQ(node.uncle(), nullptr);
}

TEST(testTree, testBSTNode_insertAsLC)
{
    BSTNode node;
    BSTNode* left = node.insertAsLC(100);
    
    EXPECT_EQ(node.isRoot(), true);
    EXPECT_EQ(node.isLChild(), false);
    EXPECT_EQ(node.isRChild(), false);
    EXPECT_EQ(node.hasLChild(), true);
    EXPECT_EQ(node.hasRChild(), false);
    EXPECT_EQ(node.hasChild(), true);
    EXPECT_EQ(node.hasParent(), false);
    EXPECT_EQ(node.hasBothChild(), false);
    EXPECT_EQ(node.isLeaf(), false);
    EXPECT_EQ(node.sibling(), nullptr);
    EXPECT_EQ(node.uncle(), nullptr);

    EXPECT_EQ(left->isRoot(), false);
    EXPECT_EQ(left->isLChild(), true);
    EXPECT_EQ(left->isRChild(), false);
    EXPECT_EQ(left->hasLChild(), false);
    EXPECT_EQ(left->hasRChild(), false);
    EXPECT_EQ(left->hasChild(), false);
    EXPECT_EQ(left->hasParent(), true);
    EXPECT_EQ(left->hasBothChild(), false);
    EXPECT_EQ(left->isLeaf(), true);
    EXPECT_EQ(left->sibling(), nullptr);
    EXPECT_EQ(left->uncle(), nullptr);
}

TEST(testTree, testBSTNode_insertAsRC)
{
    BSTNode node;
    BSTNode *right = node.insertAsRC(200);
    EXPECT_EQ(node.isRoot(), true);
    EXPECT_EQ(node.isLChild(), false);
    EXPECT_EQ(node.isRChild(), false);
    EXPECT_EQ(node.hasLChild(), false);
    EXPECT_EQ(node.hasRChild(), true);
    EXPECT_EQ(node.hasChild(), true);
    EXPECT_EQ(node.hasParent(), false);
    EXPECT_EQ(node.hasBothChild(), false);
    EXPECT_EQ(node.isLeaf(), false);
    EXPECT_EQ(node.sibling(), nullptr);
    EXPECT_EQ(node.uncle(), nullptr);

    EXPECT_EQ(right->isRoot(), false);
    EXPECT_EQ(right->isLChild(), false);
    EXPECT_EQ(right->isRChild(), true);
    EXPECT_EQ(right->hasLChild(), false);
    EXPECT_EQ(right->hasRChild(), false);
    EXPECT_EQ(right->hasChild(), false);
    EXPECT_EQ(right->hasParent(), true);
    EXPECT_EQ(right->hasBothChild(), false);
    EXPECT_EQ(right->isLeaf(), true);
    EXPECT_EQ(right->sibling(), nullptr);
    EXPECT_EQ(right->uncle(), nullptr);
}

TEST(testTree, testBSTNode_insertAsRCAndinsertAsLC)
{
    BSTNode node;
    BSTNode *left = node.insertAsLC(100);
    BSTNode *right = node.insertAsRC(200);
    EXPECT_EQ(node.isRoot(), true);
    EXPECT_EQ(node.isLChild(), false);
    EXPECT_EQ(node.isRChild(), false);
    EXPECT_EQ(node.hasLChild(), true);
    EXPECT_EQ(node.hasRChild(), true);
    EXPECT_EQ(node.hasChild(), true);
    EXPECT_EQ(node.hasParent(), false);
    EXPECT_EQ(node.hasBothChild(), true);
    EXPECT_EQ(node.isLeaf(), false);
    EXPECT_EQ(node.sibling(), nullptr);
    EXPECT_EQ(node.uncle(), nullptr);

    EXPECT_EQ(right->isRoot(), false);
    EXPECT_EQ(right->isLChild(), false);
    EXPECT_EQ(right->isRChild(), true);
    EXPECT_EQ(right->hasLChild(), false);
    EXPECT_EQ(right->hasRChild(), false);
    EXPECT_EQ(right->hasChild(), false);
    EXPECT_EQ(right->hasParent(), true);
    EXPECT_EQ(right->hasBothChild(), false);
    EXPECT_EQ(right->isLeaf(), true);
    EXPECT_EQ(right->sibling(), left);
    EXPECT_EQ(left->sibling(), right);
    EXPECT_EQ(right->uncle(), nullptr);
    node.updateHeight();
    EXPECT_EQ(node.getHeight(), 0);
}

#include "tree/BinarySearchTree.h"

TEST(testTree, test_insertAsRoot)
{
    BinarySearchTree tree;
    BSTNode *n1 = tree.insertAsRoot(1);
    EXPECT_EQ(tree.getSize(), 1);
    BSTNode* n2 = tree.insertAsLC(n1, 2);
    BSTNode* n3 = tree.insertAsLC(n2, 3);
    EXPECT_EQ(tree.getSize(), 3);
    EXPECT_EQ(n1->getHeight(), 2);
}



TEST(testTree, test_TraversePre_I1)
{
    BinarySearchTree tree;
    BSTNode *n1 = tree.insertAsRoot(1);
    BSTNode* n2 = tree.insertAsLC(n1, 2);
    BSTNode* n3 = tree.insertAsLC(n2, 3);
    BSTNode* n4 = tree.insertAsRC(n1, 4);
    BSTNode* n5 = tree.insertAsRC(n3, 5);
    vector<int> src {1,2,3,5,4};
    vector<int> dst;
    tree.traversePre_I1(n1, dst);
    cout<<endl << "dst: ";
    for(int i=0; i<dst.size(); i++)
    {
        cout << dst[i] << " ";
    }
    cout << endl;
    EXPECT_EQ(src, dst);
}

TEST(testTree, test_TraverseIn_I1)
{
    BinarySearchTree tree;
    BSTNode *n1 = tree.insertAsRoot(1);
    BSTNode* n2 = tree.insertAsLC(n1, 2);
    BSTNode* n3 = tree.insertAsLC(n2, 3);
    BSTNode* n4 = tree.insertAsRC(n1, 4);
    BSTNode* n5 = tree.insertAsRC(n3, 5);
    vector<int> src {3,5,2,1,4};
    vector<int> dst;
    tree.traverseIn_I1(n1, dst);
    cout<<endl << "dst: ";
    for(int i=0; i<dst.size(); i++)
    {
        cout << dst[i] << " ";
    }
    cout << endl;
    EXPECT_EQ(src, dst);
    BSTNode *succ = n5->succOfInOrder();
    EXPECT_EQ(succ, n2);
}

TEST(testTree, test_TraverseIn_I2)
{
    BinarySearchTree tree;
    BSTNode *n1 = tree.insertAsRoot(1);
    BSTNode* n2 = tree.insertAsLC(n1, 2);
    BSTNode* n3 = tree.insertAsLC(n2, 3);
    BSTNode* n4 = tree.insertAsRC(n1, 4);
    BSTNode* n5 = tree.insertAsRC(n3, 5);
    vector<int> src {3,5,2,1,4};
    vector<int> dst;
    tree.traverseIn_I2(n1, dst);
    cout<<endl << "dst: ";
    for(int i=0; i<dst.size(); i++)
    {
        cout << dst[i] << " ";
    }
    cout << endl;
    EXPECT_EQ(src, dst);
    BSTNode *succ = n5->succOfInOrder();
    EXPECT_EQ(succ, n2);
}

TEST(testTree, test_TraversePost_I2)
{
    BinarySearchTree tree;
    BSTNode *n1 = tree.insertAsRoot(1);
    BSTNode* n2 = tree.insertAsLC(n1, 2);
    BSTNode* n3 = tree.insertAsLC(n2, 3);
    BSTNode* n4 = tree.insertAsRC(n1, 4);
    BSTNode* n5 = tree.insertAsRC(n3, 5);
    vector<int> src {5,3,2,4,1};
    vector<int> dst;
    tree.traversePost_I1(n1, dst);
    cout<<endl << "dst: ";
    for(int i=0; i<dst.size(); i++)
    {
        cout << dst[i] << " ";
    }
    cout << endl;
    EXPECT_EQ(src, dst);

}