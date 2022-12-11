#pragma once

#include <cstdint>
#include <functional>

namespace day11 {

struct monkey
{
    std::vector<std::int64_t> items;
    std::function<std::int64_t (std::int64_t)> op;
    int div;
    int true_case;
    int false_case;
};

inline monkey test_monkeys[] = {
    {{79, 98},
     [](std::int64_t old) {return old * 19;},
     23, 2, 3},

    {{54, 65, 75, 74},
     [](std::int64_t old) {return old + 6;},
     19, 2, 0},

    {{79, 60, 97},
     [](std::int64_t old) {return old * old;},
     13, 1, 3},

    {{74},
     [](std::int64_t old) {return old + 3;},
     17, 0, 1},
};

inline monkey monkeys[] = {
    {{75, 63},
     [](std::int64_t old) {return old * 3;},
     11, 7, 2},

    {{65, 79, 98, 77, 56, 54, 83, 94},
     [](std::int64_t old) {return old + 3;},
     2, 2, 0},

    {{66},
     [](std::int64_t old) {return old + 5;},
     5, 7, 5},

    {{51, 89, 90},
     [](std::int64_t old) {return old * 19;},
     7, 6, 4},

    {{75, 94, 66, 90, 77, 82, 61},
     [](std::int64_t old) {return old + 1;},
     17, 6, 1},

    {{53, 76, 59, 92, 95},
     [](std::int64_t old) {return old + 2;},
     19, 4, 3},

    {{81, 61, 75, 89, 70, 92},
     [](std::int64_t old) {return old * old;},
     3, 0, 1},

    {{81, 86, 62, 87},
     [](std::int64_t old) {return old + 8;},
     13, 3, 5},
};
}  // namespace day11
