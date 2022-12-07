#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day7.hpp"

using namespace std;
using namespace day7;

namespace {
/// Find directory to delete to free enough space.
/// https://adventofcode.com/2022/day/7#part2
puzzle_reg _{"7.2", []{
    istringstream in{day7::terminal};
    dir root;
    process_dir(in, root);

    dir_sizes_t dir_sizes;
    compute_sizes(root, dir_sizes);

    constexpr int space_total = 70'000'000;
    constexpr int space_needed = 30'000'000;
    int space_find = space_needed - (space_total - *dir_sizes.begin());
    assert(space_find > 0);

    int delete_size = 0;
    for (int s: dir_sizes)
        if (space_find < s)
            delete_size = s;
        else
            break;

    fmt::print("Size of directory to delete: {}\n", delete_size);
}};
}
