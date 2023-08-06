# Advent of Code 2022

## Configure and build

```shell
$ mkdir build
$ cd build
$ conan install .. -s build_type=Debug --build=fmt/10.0.0

# make vscode configure automatically
$ cd ..
$ code .

# or do it manually
$ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE --preset conan-debug ..
```

## Run puzzle solvers

```shell
# day 1 puzzle 2
$ build/advent22 1.2
```
