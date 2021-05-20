cmake_minimum_required(VERSION 3.19)
project(binarytree)

set(CMAKE_CXX_STANDARD 14)
add_executable(demo Demo.cpp sources/BinaryTree.cpp sources/BinaryTree.hpp sources/BTIterator.cpp sources/BTIterator.hpp)
add_executable(test Test.cpp sources/BinaryTree.cpp sources/BinaryTree.hpp sources/BTIterator.cpp sources/BTIterator.hpp)
