# Advent of Code 2022

## Configure and build

```shell
$ mkdir build
$ conan install . --output-folder=build --build=missing -s build_type=Debug

# make vscode configure automatically
$ code .

# or do it manually
$ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE --preset conan-debug .
$ cmake --build build
```

## Run puzzle solvers

```shell
# day 1 puzzle 2
$ build/advent22 1.2
```
