cmake_minimum_required(VERSION 3.19)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(prak04_sorting)

set(CMAKE_CXX_STANDARD 14)

add_executable(prak04_sorting main.cpp catch.h hashtable.h hashtable.cpp sorting.h sorting.cpp unit_tests.cpp)

find_package(OpenMP REQUIRED)
if(NOT TARGET OpenMP::OpenMP_CXX)
    add_library(OpenMP_TARGET INTERFACE)
    add_library(OpenMP::OpenMP_CXX ALIAS OpenMP_TARGET)
    target_compile_options(OpenMP_TARGET INTERFACE ${OpenMP_CXX_FLAGS})
    find_package(Threads REQUIRED)
    target_link_libraries(OpenMP_TARGET INTERFACE Threads::Threads)
    target_link_libraries(OpenMP_TARGET INTERFACE ${OpenMP_CXX_FLAGS})
endif()

target_link_libraries(prak04_sorting PUBLIC OpenMP::OpenMP_CXX)