#!/bin/bash

# Just a simple script to build all tests, run them, show the results, and clean up.

echo " "
echo "--------------------"
echo "compile all tests"
g++ -o test_suite.out main.cpp test*.cpp

echo " "
echo "--------------------"
echo "run tests"
echo " "
./test_suite.out --durations yes --verbosity normal

echo "--------------------"
echo "cleanup"
rm ./test_suite.out

echo " "