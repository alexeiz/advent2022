#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day6.hpp"

using namespace std;
namespace views = ranges::views;

namespace {
/// Find the start-of-packet marker.
/// https://adventofcode.com/2022/day/6
puzzle_reg _{"6.1", []{
    constexpr int marker_len = 4;
    auto datastream = string_view(day6::datastream);
    vector<char> marker{datastream.begin(), datastream.begin() + marker_len};

    int pos = marker_len;
    for (auto c: datastream | views::drop(marker_len))
    {
        if (marker[0] != marker[1] && marker[0] != marker[2] && marker[0] != marker[3] &&
            marker[1] != marker[2] && marker[1] != marker[3] &&
            marker[2] != marker[3])
        {
            break;
        }

        ++pos;
        ranges::rotate(marker, marker.begin() + 1);
        marker.back() = c;
    }

    fmt::print("Start of packet marker at pos: {}\n", pos);
}};
}
