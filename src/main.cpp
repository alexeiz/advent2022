#include "common.hpp"
#include "puzzle_reg.hpp"

using namespace std;

auto & puzzles = puzzle_reg::puzzles;

int main(int argc, char * argv[])
{
    if (argc < 2)
    {
        fmt::print(cerr, "options: day.puzzle (e.g: 1.1)\n");
        return 1;
    }

    auto puz_name = argv[1];
    auto puzzle = puzzles.find(puz_name);
    if (puzzle == puzzles.end())
    {
        fmt::print(cerr, "puzzle '{}' not found\n", puz_name);
        return 1;
    }

    puzzle->second();
}
