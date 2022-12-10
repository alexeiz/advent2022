#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day10.hpp"

using namespace std;

namespace {
/// Draw pixels on CRT.
/// https://adventofcode.com/2022/day/10#part2
puzzle_reg _{"10.2", []{
    auto & prog = day10::prog;
    int clock = 0;
    int xreg = 1;
    constexpr int crt_width = 40;
    constexpr int crt_height = 6;
    bool crt[crt_width][crt_height] = {};

    auto draw_pixel = [&] {
        int row = clock / crt_width;
        int col = clock % crt_width;
        if (xreg - 1 <= col && col <= xreg + 1)
            crt[col][row] = true;
    };

    for (auto & [inst, op]: prog)
    {
        switch (inst)
        {
        case 0:
            draw_pixel();
            ++clock;
            break;
        case day10::addx:
            draw_pixel();
            ++clock;
            draw_pixel();
            ++clock;
            xreg += op;
            break;
        }
    }

    for (int i: views::iota(0, crt_height))
    {
        for (int j: views::iota(0, crt_width))
            putchar(crt[j][i] ? '#' : '.');
        fmt::print("\n");
    }
}};
}
