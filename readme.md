# Advent of Code 2022

## Configure and build

```shell
$ mkdir build
$ cd build
$ conan install .. --build=fmt -s build_type=Debug

# make vscode configure automatically
$ cd ..
$ code .

# or do it manually
$ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE:FILEPATH=conan_toolchain.cmake -S.. -B. -G Ninja
```

## Run puzzle solvers

```shell
# day 1 puzzle 2
$ build/advent22 1.2
```
