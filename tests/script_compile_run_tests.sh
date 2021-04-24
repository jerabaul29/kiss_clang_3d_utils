#!/bin/bash

# Just a simple script to build all tests, run them, show the results, and clean up.

echo " "
echo "--------------------"
echo "compile all tests"

# to use flags
FLAGS="-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wconversion -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -fno-common -std=c++1z"

# to use no flags
#FLAGS=""

g++ $FLAGS -o test_suite.out main.cpp test*.cpp

echo " "
echo "--------------------"
echo "run tests"
echo " "
./test_suite.out --durations yes --verbosity normal

echo "--------------------"
echo "cleanup"
rm ./test_suite.out

echo " "
