#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day1.hpp"

using namespace std;

namespace {
/// Calculate maximum calories of top three.
/// https://adventofcode.com/2022/day/1#part2
puzzle_reg _{"1.2", []{
    vector<int> elves;
    int cur_cal = 0;
    for (auto cal_v: day1::calories)
    {
        if (cal_v != -1)
            cur_cal += cal_v;
        else
        {
            elves.push_back(cur_cal);
            cur_cal = 0;
        }
    }

    ranges::partial_sort(elves, elves.begin() + 3, ranges::greater{});
    auto max_of3 = elves[0] + elves[1] + elves[2];
    fmt::print(cout, "max of 3 calories: {}\n", max_of3);
}};
}
