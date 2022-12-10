#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day10.hpp"

using namespace std;

namespace {
/// Find the signal strength.
/// https://adventofcode.com/2022/day/10
puzzle_reg _{"10.1", []{
    auto & prog = day10::prog;
    int clock = 1;
    int xreg = 1;
    int signal = 0;

    auto check_signal = [&] {
        if ((clock - 20) % 40 == 0)
            signal += xreg * clock;
    };

    for (auto & [inst, op]: prog)
    {
        switch (inst)
        {
        case 0:
            check_signal();
            ++clock;
            break;
        case day10::addx:
            check_signal();
            ++clock;
            check_signal();
            ++clock;
            xreg += op;
            break;
        }
    }

    fmt::print("Signal strength: {}\n", signal);
}};
}
