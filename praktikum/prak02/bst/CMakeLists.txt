cmake_minimum_required(VERSION 3.19)
project(bst)

set(CMAKE_CXX_STANDARD 14)

add_executable(bst main.cpp catch.h Tree.cpp Tree.h TreeNode.h TreeNode.cpp TreeTest.cpp)