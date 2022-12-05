#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day3.hpp"

using namespace std;
namespace views = ranges::views;

namespace {
/// Calculate priority of misplaced items.
/// https://adventofcode.com/2022/day/3
puzzle_reg _{"3.1", []{
    int total_pri = 0;
    for (string_view rs: day3::rucksacks)
    {
        bool items[256] = {};
        auto size2 = rs.size() / 2;
        for (int it: views::take(rs, size2))
            items[it] = true;

        for (int it: views::drop(rs, size2))
        {
            if (items[it])
            {
                if (it <= 'Z')
                    total_pri += it - 'A' + 27;
                else
                    total_pri += it - 'a' + 1;

                break;
            }
        }
    }

    fmt::print("total priority: {}\n", total_pri);
}};
}
