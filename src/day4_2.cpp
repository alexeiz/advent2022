#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day4.hpp"

using namespace std;

namespace {
/// Count the number of overlapping section ranges.
/// https://adventofcode.com/2022/day/4#part2
puzzle_reg _{"4.2", []{
    int overlapping = 0;
    for (auto const & [rng1, rng2]: day4::sections)
    {
        auto const & [r1x, r1y] = rng1;
        auto const & [r2x, r2y] = rng2;
        if ((r1x <= r2x and r2x <= r1y) or (r2x <= r1x and r1x <= r2y))
            ++overlapping;
    }

    fmt::print("total overlapping section ranges: {}\n", overlapping);
}};
}
