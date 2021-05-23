cmake_minimum_required(VERSION 3.19)
project(binarytree)

set(CMAKE_CXX_STANDARD 11)
add_executable(demo Demo.cpp sources/BinaryTree.cpp sources/BinaryTree.hpp)
add_executable(test Test.cpp sources/BinaryTree.cpp sources/BinaryTree.hpp)
add_executable(main main.cpp)
