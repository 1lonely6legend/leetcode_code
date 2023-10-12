cmake_minimum_required(VERSION 3.23)

project(leetcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(scorpio
        BinTree/113.cpp
)
add_executable(test "BinTree/(适用于完全二叉树)从二叉树表示数组生成二叉树.cpp")