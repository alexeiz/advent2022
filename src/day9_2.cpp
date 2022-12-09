#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day9.hpp"

using namespace std;
using pos_t = tuple<int, int>;

namespace {
/// How many positions the tail of the rope visits at least once.
/// https://adventofcode.com/2022/day/9#part2
puzzle_reg _{"9.2", []{
    auto & motions = day9::motions;

    vector<pos_t> knots(10);
    auto & head = knots.front();
    auto & tail = knots.back();

    set<pos_t> visited;
    visited.insert(tail);

    auto adj_coord = [](int & h, int & t, bool diag) {
        if (abs(h - t) > 1 || diag)
            t += h > t ? 1 : -1;
    };

    for (auto const & m: motions)
    {
        for ([[maybe_unused]] auto _: views::iota(0, m.steps))
        {
            head = tuple{get<0>(head) + m.d.x, get<1>(head) + m.d.y};

            auto [hx, hy] = head;
            for (auto it = next(knots.begin()); it != knots.end(); ++it)
            {
                auto & [tx, ty] = *it;

                bool diag = (abs(hx - tx) + abs(hy - ty) > 2);
                adj_coord(hx, tx, diag);
                adj_coord(hy, ty, diag);

                hx = tx;
                hy = ty;
            }

            visited.insert(tail);
        }
    }

    fmt::print("Number of positions the tail visited: {}\n", visited.size());
}};
}
