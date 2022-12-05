#include <algorithm>
#include <iostream>

#include <fmt/core.h>
#include <fmt/ostream.h>

#include "day1.hpp"

using namespace std;

/// @brief Calculate maximum calories
/// https://adventofcode.com/2022/day/1
void day1_1()
{
    int max_cal = 0;
    int cur_cal = 0;
    for (auto cal_v: day1::calories)
    {
        if (cal_v != -1)
            cur_cal += cal_v;
        else
        {
            max_cal = max(max_cal, cur_cal);
            cur_cal = 0;
        }
    }

    fmt::print(cout, "max calories: {}\n", max_cal);
}
