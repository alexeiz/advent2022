#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day8.hpp"

using namespace std;

namespace {
int scan_distance(char const * grid, int grid_size, int x, int y, int dx, int dy)
{
    int dist = 0;

    for (char tree_h = grid[x + y * grid_size];
         0 <= x && x < grid_size && 0 <= y && y < grid_size;
         x += dx, y += dy, ++dist)
    {
        if (dist && tree_h <= grid[x + y * grid_size])
        {
            ++dist;
            break;
        }
    }

    return dist - 1;
}

/// Calculate best scenic score.
/// https://adventofcode.com/2022/day/8#part2
puzzle_reg _{"8.2", []{
    constexpr int grid_size = day8::size;
    auto grid = day8::grid;

    int best_scenic = 0;
    for (int x = 1; x != grid_size - 1; ++x)
        for (int y = 1; y != grid_size - 1; ++y)
        {
            int scenic = scan_distance(grid, grid_size, x, y, 1, 0)
                       * scan_distance(grid, grid_size, x, y, 0, 1)
                       * scan_distance(grid, grid_size, x, y, -1, 0)
                       * scan_distance(grid, grid_size, x, y, 0, -1);
            best_scenic = max(best_scenic, scenic);
        }

    fmt::print("Best scenic score: {}\n", best_scenic);
}};
}
