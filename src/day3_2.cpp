#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day3.hpp"

using namespace std;

namespace {
/// Calculate priorities group badges.
/// https://adventofcode.com/2022/day/3#part2
puzzle_reg _{"3.2", []{
    int total_pri = 0;

    const int group_max = 8;
    const int group_all = 7;

    int group_bit = 1;
    int items[256] = {};
    for (string_view rs: day3::rucksacks)
    {
        for (int it: rs)
        {
            items[it] |= group_bit;
            if (items[it] == group_all)
            {
                // found group badge
                if (it <= 'Z')
                    total_pri += it - 'A' + 27;
                else
                    total_pri += it - 'a' + 1;

                break;
            }
        }

        group_bit <<= 1;
        if (group_bit == group_max)
        {
            group_bit = 1;
            ranges::fill(items, 0);
        }
    }

    fmt::print("total group badge priority: {}\n", total_pri);
}};
}
