#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day2.hpp"

using namespace std;

namespace {
int score_table[3][3] = {  // [your_move][op_move]
    {3, 0, 6},
    {6, 3, 0},
    {0, 6, 3},
};

/// Calculate score for strategy.
/// https://adventofcode.com/2022/day/2
puzzle_reg _{"2.1", []{
    int score = 0;
    for (auto const & [op_move, your_move]: day2::strat)
        score += score_table[your_move - 'X'][op_move - 'A'] + (your_move - 'X') + 1;

    fmt::print("your total score: {}\n", score);
}};
}
