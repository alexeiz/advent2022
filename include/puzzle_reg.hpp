#pragma once

#include <functional>
#include <map>
#include <string_view>

struct puzzle_reg
{
    inline static std::map<std::string_view, std::function<void ()>> puzzles;

    puzzle_reg(std::string_view tag, auto && puzzle_fn)
    {
        puzzles[tag] = puzzle_fn;
    }
};
