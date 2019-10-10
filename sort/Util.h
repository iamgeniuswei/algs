//
// Created by developer on 2019/9/2.
//

#ifndef ALGS_UTIL_H
#define ALGS_UTIL_H

#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
using namespace std::chrono;
class Util {
public:
    static void timeElapsed(system_clock::time_point start, system_clock::time_point end)
    {
        auto duration = duration_cast<microseconds>(end-start);
        cout << "Time Elapsed: " << double(duration.count()) * microseconds::period::num / microseconds::period::den << "s" <<endl;
    }
    static vector<int> readData(string& path)
    {
        vector<int> nums;
        fstream fin;
        fin.open(path, ios::in);
        if(!fin.is_open())
            return nums;
        char line[32];
        while (fin.getline(line, 32))
        {
            int value = atoi(line);
            nums.push_back(value);
        }
        return nums;
    }
};


#endif //ALGS_UTIL_H
