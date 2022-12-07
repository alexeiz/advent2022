#include "common.hpp"
#include "puzzle_reg.hpp"
#include "day7.hpp"

using namespace std;

namespace {
struct file
{
    int size;
};

struct dir
{
    vector<variant<file, dir>> nodes;
};

void process_dir(istringstream & in, dir & cwd)
{
    string line;
    while (getline(in, line))
    {
        if (line.starts_with("$ cd /"))
            continue;  // root dir

        if (line.starts_with("$ cd .."))
            return;  // exit dir

        if (line.starts_with("$ cd "))
        {
            // subdirectory
            auto & subdir = cwd.nodes.emplace_back(dir{});
            process_dir(in, get<dir>(subdir));
        }

        // try to interpret as file size
        try
        {
            int size = stoi(line);
            cwd.nodes.emplace_back(file{size});
        }
        catch(std::exception & e)  // not a number
        {}
    }
}

using dir_sizes_t = multiset<int, greater<>>;

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

int compute_sizes(dir const & cwd, dir_sizes_t & dir_sizes)
{
    int total = 0;
    for (auto const & n: cwd.nodes)
    {
        visit(overloaded{
                [&](dir const & d) {total += compute_sizes(d, dir_sizes);},
                [&](file const & f) {total += f.size;}
            }, n);
    }

    dir_sizes.insert(total);
    return total;
}

/// Find the sum of the total sizes of directories.
/// https://adventofcode.com/2022/day/7
puzzle_reg _{"7.1", []{
    istringstream in{day7::terminal};
    dir root;
    process_dir(in, root);

    dir_sizes_t dir_sizes;
    compute_sizes(root, dir_sizes);

    int sum = 0;
    constexpr int limit = 100000;
    for (int s: dir_sizes)
        if (s < limit)
            sum += s;

    fmt::print("Total sum of dir sizes <{}: {}\n", limit, sum);
}};
}
