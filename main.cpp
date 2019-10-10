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