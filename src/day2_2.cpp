#include "common.hpp"
#include "day2.hpp"

using namespace std;

namespace {
int score_table[3][3] = {  // [your_move][op_move]
    {3, 0, 6},
    {6, 3, 0},
    {0, 6, 3},
};

int move_table[3][3] = {  // [op_move][result]
    {2, 0, 1},
    {0, 1, 2},
    {1, 2, 0},
};
}

/// @brief Calculate score for strategy with given end results
/// https://adventofcode.com/2022/day/2#part2
void day2_2()
{
    int score = 0;
    for (auto const & [op_move, result]: day2::strat)
    {
        int your_move = move_table[op_move - 'A'][result - 'X'];
        score += score_table[your_move][op_move - 'A'] + your_move + 1;
    }

    fmt::print("your total score: {}\n", score);
}
