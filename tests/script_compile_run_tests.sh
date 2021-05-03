#!/bin/bash

# Just a simple script to build all tests, run them, show the results, and clean up.

# TODO
# consider if moving to some form of make or cmake may be cleaner

# warning flags
WFLAGS="-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wconversion -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -fno-common -std=c++1z -Wfloat-conversion"

echo " "
echo "We will run all tests twice:"
echo "for double: -DF_TYPE_SWITCH=\"'D'\""
echo "for float: -DF_TYPE_SWITCH=\"'F'\""

echo " "
echo "--------------------"
echo "compile all tests for double"

g++ $WFLAGS -DF_TYPE_SWITCH="'D'" -DKISS_CLANG_3D_IGNORE_DEPRECATED -o test_suite.out main.cpp test*.cpp

echo " "
echo "--------------------"
echo "run tests for double"
echo " "
./test_suite.out --durations yes --verbosity normal

echo "--------------------"
echo "cleanup double test"
rm ./test_suite.out

echo " "
echo "--------------------"
echo "compile all tests for float"

g++ $WFLAGS -DF_TYPE_SWITCH="'F'" -DKISS_CLANG_3D_IGNORE_DEPRECATED -fsingle-precision-constant -o test_suite.out main.cpp test*.cpp

echo " "
echo "--------------------"
echo "run tests for float"
echo " "
./test_suite.out --durations yes --verbosity normal

echo "--------------------"
echo "cleanup float test"
rm ./test_suite.out

echo " "
