# Advent of code 2022

## Configure and build

```shell
$ mkdir build
$ cd build
$ conan install ..

# make vscode configure automatically
$ cd ..
$ code .

# or do it manually
$ cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE:FILEPATH=conan_toolchain.cmake -S.. -B. -G Ninja
```
