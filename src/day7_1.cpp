#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day7.hpp"

using namespace std;
using namespace day7;

namespace {
/// Find the sum of the total sizes of directories.
/// https://adventofcode.com/2022/day/7
puzzle_reg _{"7.1", []{
    istringstream in{terminal};
    dir root;
    process_dir(in, root);

    dir_sizes_t dir_sizes;
    compute_sizes(root, dir_sizes);

    constexpr int limit = 100000;
    int sum = accumulate(dir_sizes.upper_bound(limit), dir_sizes.end(), 0);

    fmt::print("Total sum of dir sizes <{}: {}\n", limit, sum);
}};
}
