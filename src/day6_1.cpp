#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day6.hpp"

using namespace std;

namespace {
/// Find the start-of-packet marker.
/// https://adventofcode.com/2022/day/6
puzzle_reg _{"6.1", []{
    constexpr int marker_len = 4;
    auto datastream = string_view(day6::datastream);

    auto marker = datastream.begin();
    auto marker_end = datastream.begin() + marker_len;

    for (; marker_end != datastream.end(); ++marker, ++marker_end)
    {
        if (*marker != *(marker + 1) && *marker != *(marker + 2) && *marker != *(marker + 3) &&
            *(marker + 1) != *(marker + 2) && *(marker + 1) != *(marker + 3) &&
            *(marker + 2) != *(marker + 3))
        {
            break;
        }
    }

    fmt::print("Start of packet marker at pos: {}\n", marker_end - datastream.begin());
}};
}
