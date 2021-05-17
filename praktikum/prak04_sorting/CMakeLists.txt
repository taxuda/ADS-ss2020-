cmake_minimum_required(VERSION 3.19)
project(prak04_sorting)

set(CMAKE_CXX_STANDARD 14)

add_executable(prak04_sorting main.cpp catch.h hashtable.h hashtable.cpp sorting.h sorting.cpp unit_tests.cpp)