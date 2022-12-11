#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day11.hpp"

using namespace std;

namespace {
///
/// https://adventofcode.com/2022/day/11#part2
puzzle_reg _{"11.2", []{
    auto & monkeys = day11::monkeys;
    vector<int64_t> inspects(std::size(monkeys));

    int max_div = 1;
    for (auto & m: monkeys)
        max_div = lcm(max_div, m.div);

    for ([[maybe_unused]] int round: views::iota(0, 10000))
    {
        int mi = 0;
        for (auto & m: monkeys)
        {
            for (auto it: m.items)
            {
                it = m.op(it) % max_div;
                assert(it > 0);
                monkeys[it % m.div == 0 ? m.true_case : m.false_case].items.push_back(it);
            }

            inspects[mi] += m.items.size();
            m.items.clear();
            ++mi;
        }
    }

    ranges::partial_sort(inspects, inspects.begin() + 2, std::greater{});
    fmt::print("The level of monkey business: {}\n", inspects[0] * inspects[1]);
}};
}
