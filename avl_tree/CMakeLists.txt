cmake_minimum_required(VERSION 3.19)
project(avl_tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(avl_tree main.cpp AVLNode.cpp AVLNode.h AVLTree.cpp AVLTree.h)