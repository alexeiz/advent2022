#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day5.hpp"

using namespace std;

namespace {
/// Which crate will end up on top of each stack after rearrangement.
/// https://adventofcode.com/2022/day/5#part2
puzzle_reg _{"5.2", []{
    for (auto [num, from, to]: day5::move_instr)
    {
        auto & from_st = day5::stacks[from - 1];
        auto & to_st = day5::stacks[to - 1];
        ranges::copy(views::drop(from_st, from_st.size() - num), back_inserter(to_st));
        from_st.erase(from_st.end() - num, from_st.end());
    }

    for (auto const & st: day5::stacks)
        fmt::print("{}", st.back());

    fmt::print("\n");
}};
}
