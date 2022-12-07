#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day6.hpp"

using namespace std;
namespace views = ranges::views;

namespace {
/// Find the start-of-message marker.
/// https://adventofcode.com/2022/day/6#part2
puzzle_reg _{"6.2", []{
    constexpr int message_len = 14;
    auto datastream = string_view(day6::datastream);

    auto message = datastream.begin();
    auto message_end = datastream.begin() + message_len;

    int chrs[0x80] = {};
    for (int c: span{message, message_end})
        ++chrs[c];

    auto check_uniq = [](span<int> const & sc) {
        return ranges::all_of(sc, [](int v) {return v <= 1;});
    };

    if (!check_uniq(chrs))
    {
        for (auto last = prev(datastream.end()); message_end != last; ++message, ++message_end)
        {
            int a = --chrs[int(*message)];
            int b = ++chrs[int(*message_end)];
            if (a == 1 && b == 1 && check_uniq(chrs))
                break;
        }
    }

    fmt::print("Start of message marker at pos: {}\n", message_end - datastream.begin() + 1);
}};
}
