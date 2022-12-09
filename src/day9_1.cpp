#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day9.hpp"

using namespace std;
using pos_t = tuple<int, int>;

namespace {
/// How many positions the tail of the rope visits at least once.
/// https://adventofcode.com/2022/day/9
puzzle_reg _{"9.1", []{
    auto & motions = day9::motions;

    pos_t head_pos{0, 0};
    pos_t tail_pos{0, 0};
    auto & [hx, hy] = head_pos;
    auto & [tx, ty] = tail_pos;

    set<pos_t> visited;
    visited.insert(tail_pos);

    auto adj_coord = [](int & h, int & t, bool diag) {
        if (abs(h - t) > 1 || diag)
            t += h > t ? 1 : -1;
    };

    for (auto const & m: motions)
    {
        for ([[maybe_unused]] auto _: views::iota(0, m.steps))
        {
            hx += m.d.x;
            hy += m.d.y;

            bool diag = (abs(hx - tx) + abs(hy - ty) > 2);
            adj_coord(hx, tx, diag);
            adj_coord(hy, ty, diag);

            visited.insert(tail_pos);
        }
    }

    fmt::print("Number of positions the tail visited: {}\n", visited.size());
}};
}
