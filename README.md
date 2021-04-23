# kiss_clang_3d_utils

A keep it stupid simple header library, in c-language, providing 3d utils such as vectors, quaternions, and related primitives.

This library was written since I needed to perform some simple 3d operations such as rotations, changes of referentials, etc, in some Arduino code. I could not find a simple, unit-tested, easy-to-use, low level library to use quaternions and I decided to write mine.

The choice of using c instead of cpp is for having the wides compatibility possible, and also to simplify the overall library design.

## Library

The whole library is provided as a single clang header file in **src/kiss_clang_3d_utils.h**.

## Tests

Tests are in the **tests** folder. For simplicity, the tests are run using *Catch2*, a cpp-lang framework for unit testing. To run all tests, just run the **tests/script_compile_run_tests.sh**.
