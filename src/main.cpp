#include <functional>
#include <iostream>
#include <map>
#include <string_view>

#include <fmt/core.h>
#include <fmt/ostream.h>
#include <fmt/printf.h>

using namespace std;
using namespace std::literals::string_view_literals;

using day_fn = function<void ()>;

void day1_1();

map<string_view, day_fn> puzzles = {
    {"1.1"sv, day1_1},
};

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
