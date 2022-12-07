#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day5.hpp"

using namespace std;

namespace {
/// Which crate will end up on top of each stack after rearrangement.
/// https://adventofcode.com/2022/day/5
puzzle_reg _{"5.1", []{
    for (auto [num, from, to]: day5::move_instr)
    {
        for ([[maybe_unused]] auto _: views::iota(0, num))
        {
            day5::stacks[to - 1].push_back(day5::stacks[from - 1].back());
            day5::stacks[from - 1].pop_back();
        }
    }

    for (auto const & st: day5::stacks)
        fmt::print("{}", st.back());

    fmt::print("\n");
}};
}
