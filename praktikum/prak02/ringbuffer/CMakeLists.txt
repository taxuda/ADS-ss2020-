cmake_minimum_required(VERSION 3.19)
project(ringbuffer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ringbuffer catch.hpp main.cpp RingTest.cpp Ring.cpp Ring.h RingNode.h RingNode.cpp print.cpp print.h)