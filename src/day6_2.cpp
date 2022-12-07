#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day6.hpp"

using namespace std;

namespace {
/// Find the start-of-message marker.
/// https://adventofcode.com/2022/day/6#part2
puzzle_reg _{"6.2", []{
    constexpr int message_len = 14;
    auto datastream = string_view(day6::datastream);

    auto message = datastream.begin();
    auto message_end = datastream.begin() + message_len;

    int chrs[0x80] = {};
    int uniqs = 0;

    auto set_char = [&](int c) {
        if (chrs[c]++ == 0)
            ++uniqs;
    };

    auto clear_char = [&](int c) {
        if (--chrs[c] == 0)
            --uniqs;
    };

    auto check_uniq = [&]() {
        return uniqs == message_len;
    };

    for (int c: span{message, message_end})
        set_char(c);

    for (auto last = prev(datastream.end()); !check_uniq() && message_end != last; ++message, ++message_end)
    {
        clear_char(*message);
        set_char(*message_end);
    }

    fmt::print("Start of message marker at pos: {}\n", message_end - datastream.begin());
}};
}
