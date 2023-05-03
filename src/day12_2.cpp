#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day12.hpp"

using namespace std;

namespace {
/// Fewest steps hill climbing
/// https://adventofcode.com/2022/day/12#part2
puzzle_reg _{"12.2", []{
    auto height_map = day12::map;
    auto map_sx = day12::map_sx;
    auto map_sy = day12::map_sy;

    // find starting point
    vector<tuple<int, int>> horizon;
    vector<vector<int>> path_map{size_t(map_sx), vector<int>(size_t(map_sy), 0)};

    int end_x = 0;
    int end_y = 0;
    for (int x = 0; x != map_sx; ++x)
        for (int y = 0; y != map_sy; ++y)
        {
            if (height_map[x][y] == 'S' or height_map[x][y] == 'a')
            {
                height_map[x][y] = 'a';
                path_map[x][y] = 1;
                horizon.emplace_back(x, y);
            }
            else if (height_map[x][y] == 'E')
            {
                end_x = x;
                end_y = y;
                height_map[x][y] = 'z';
            }
        }

    auto fill_path_astar = [&]{
        vector<tuple<int, int>> dxdy{{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

        while (horizon.size())
        {
            decltype(horizon) new_hor;
            for (auto && [x, y]: horizon)
            {
                auto height = height_map[x][y] + 1;
                int step = path_map[x][y] + 1;

                for (auto && [dx, dy]: dxdy)
                {
                    int x1 = x + dx;
                    int y1 = y + dy;
                    if (x1 < 0 or x1 >= map_sx or y1 < 0 or y1 > map_sy)
                        continue;  // out of bounds

                    if (height_map[x1][y1] <= height and (path_map[x1][y1] == 0 or path_map[x1][y1] > step))
                    {
                        path_map[x1][y1] = step;
                        new_hor.emplace_back(x1, y1);
                    }
                }
            }

            using std::swap;
            swap(horizon, new_hor);
        }
    };

    fill_path_astar();
    fmt::print("Fewest number of steps: {}\n", path_map[end_x][end_y] - 1);
}};
}
