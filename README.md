# kiss_clang_3d_utils

A keep it stupid (but not too stupid either...), simple, library, in c-language, providing 3d utils such as vectors, quaternions, and related primitives.

This library was written since I needed to perform some simple 3d operations such as rotations, changes of referentials, etc, in some Arduino code. I could not find a simple, unit-tested, easy-to-use, fast, low level library to use quaternions and I decided to write mine.

The choice of using c instead of cpp is for having the wides compatibility possible, and also to simplify the overall library design. Note that the core of the library, i.e the **src/kiss_clang_3d.h/c**, are compatible with pure C, but that extra components are C++ only for simplicity of implementation. In particular, the src extra utils are C++ only, and the test suite is also based on the C++ catch2 unit test framework.

The aim is to keep the code as simple and short as possible, but not too simple either. For example, calculating the rotation of a vector by a quaternion is implemented using the Rodriguez method, which is much more computationally efficient than a naive double quaternion product.

## Library installation

The whole library is provided as a couple of clang files, i.e. **src/kiss_clang_3d_utils.h/c**. Copy these and / or make it accessible to your project, and you are ready to go. The only thing you should need to do is to set the fundamental type you want to use in the ```#define F_TYPE``` definition at the start of the header. Both ```float``` and ```double``` should work nicely. Both are unit tested.

Made available under the MIT license: no guarantees whatsoever, but do whatever you want with it.

## Tests

Tests are in the **tests** folder. For simplicity, the tests are run using *Catch2*, a cpp-lang framework for unit testing. To run all tests, just run the **tests/script_compile_run_tests.sh**. That will run all tests twice actually, once with fundamental type float, and once with fundamental type double. Unit testing happens with quite aggressive flags, for example, unintended type conversions should be treated as an error.
