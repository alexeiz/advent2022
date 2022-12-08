#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day8.hpp"

using namespace std;

namespace {
void scan_grid(char const * grid, int grid_size, auto minmax, int x, int y, int dx, int dy)
{
    int height = -1;

    for (; 0 <= x && x < grid_size && 0 <= y && y < grid_size; x += dx, y += dy)
    {
        minmax[x][y] = min(minmax[x][y], height);
        height = max(height, grid[x + y * grid_size] - '0');
    }
}

/// Find visible trees.
/// https://adventofcode.com/2022/day/8
puzzle_reg _{"8.1", []{
    constexpr int grid_size = day8::size;
    auto grid = day8::grid;

    int minmax[grid_size][grid_size];

    for (int i = 0; i != grid_size; ++i)
        for (int j = 0; j != grid_size; ++j)
            minmax[i][j] = grid[i + j * grid_size] - '0';

    for (int n = 0; n != grid_size; ++n)
    {
        scan_grid(grid, grid_size, minmax, n, 0, 0, 1);
        scan_grid(grid, grid_size, minmax, 0, n, 1, 0);
        scan_grid(grid, grid_size, minmax, n, grid_size - 1, 0, -1);
        scan_grid(grid, grid_size, minmax, grid_size - 1, n, -1, 0);
    }

    int visible = 0;
    for (int i = 0; i != grid_size; ++i)
        for (int j = 0; j != grid_size; ++j)
            visible += (minmax[i][j] < grid[i + j * grid_size] - '0');

    fmt::print("Trees are visible from outside the grid: {}\n", visible);
}};
}
