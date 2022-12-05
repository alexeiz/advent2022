#include "common.hpp"
#include "day2.hpp"

using namespace std;

int score_table[3][3] = {
    {3, 0, 6},
    {6, 3, 0},
    {0, 6, 3},
};

/// @brief Calculate score for strategy
/// https://adventofcode.com/2022/day/2
void day2_1()
{
    int score = 0;
    for (auto const & [op_move, your_move]: day2::strat)
        score += score_table[your_move - 'X'][op_move - 'A'] + (your_move - 'X') + 1;

    fmt::print("your total score: {}\n", score);
}
