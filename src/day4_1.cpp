#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day4.hpp"

using namespace std;
namespace views = ranges::views;

namespace {
/// Count the number of overlapping section ranges.
/// https://adventofcode.com/2022/day/4
puzzle_reg _{"4.1", []{
    int overlapping = 0;
    for (auto const & [rng1, rng2]: day4::sections)
    {
        auto const & [r1x, r1y] = rng1;
        auto const & [r2x, r2y] = rng2;
        if ((r1x <= r2x and r2y <= r1y) or (r2x <= r1x and r1y <= r2y))
            ++overlapping;
    }

    fmt::print("total overlapping section ranges: {}\n", overlapping);
}};
}
